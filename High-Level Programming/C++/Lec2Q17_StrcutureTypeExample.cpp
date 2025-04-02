# include <iostream>
using namespace std;

struct AccountV1 // Structure for a bank certificate of deposit
// AccountV1 is the name of the new struct "type"
{
    // the following are member variables. They are parts of the structure variable.
    // Note that different structs can have same name member variables without conflicts
    double balance; // member names
    double interestRate;
    int term;
}; // REQUIRED semicolon, it is required since you technically can declare structure variables in this location

void getData (AccountV1 &theAccount); // function prototype
// Very important note: if this prototype came before the structure the compiler throws an error
// because it still doesn't know what type AccountV1 is.

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

int main ()
{
    AccountV1 account; // variable account of type AccountV1
    getData (account); 
    // account is a suitable variable to pass because it is of type AccountV1 as per the prototype 
    // instruction of function getData

    double rateFraction, interest; // variables declarations

    rateFraction = account.interestRate/100.0; 
    // notice how the name of the variable of struct type AccountV1 is used with the dot operator to 
    // access the structure member interestRate
    interest = account.balance*(rateFraction*(account.term/12.0));
    // notice how the name of the variable of struct type AccountV1 is used with the dot operator to 
    // access the structure members balance and term
    account.balance = account.balance + interest;
    // notice how the name of the variable of struct type AccountV1 is used with the dot operator to 
    // access the structure member balance


    // These are used for formatting the command line UI - they do output formatting 
    // setf Sets the formatting flags to specified settings
    // Manipulate cout Object using C++ IOS Library
    cout.setf(ios::fixed); 
    // makes cout print floats with a fixed number of decimals
    cout.setf(ios::showpoint); 
    // displays decimal and trailing zeros for all floating point numbers, even if the decimal places aren't needed.
    cout.precision(2); 
    // sets the number of decimal places to be 2 - note that it does rount up

    // the :: symbol is called the scope resolution operator and it can be used to identify a member of a namespace (our case)
    // The scope resolution operator can also be used to get the hidden names due to variable scopes so that you can still use them.
    // List of cases it can be used in:
    // 1. Accessing a global variable when there is a local variable with same name
    // 2. Defining a function outside a class
    // 3. Accessing a class’s static variables
    // 4. Referring to a class inside another class
    // 5. In case of multiple Inheritance
    // 6. Namespace

    cout<<"When your certificate of deposit matures in " << account.term << " months, it will have a " << 
    "balance of $" << account.balance << endl;

    return 0;
}

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

void getData (AccountV1 &theAccount) 
// theAccount variable is of type AccountV1 and it is pass by reference as per the & operator
// theAccount variable will be used just like the account variable has been used in the main function
// with the dot operator to access the members of the structure
{
    cout << "Enter the account balance: $";
    cin >> theAccount.balance;
    cout << "Enter account interest rate: ";
    cin >> theAccount.interestRate;
    cout << "Enter the number of months until maturity: ";
    cin >> theAccount.term;
}
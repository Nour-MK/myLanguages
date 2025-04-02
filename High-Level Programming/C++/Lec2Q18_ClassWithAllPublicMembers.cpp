#include <iostream>
using namespace std;

/* ████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████ */

class DayOfYear // DayOfYear is the name of the class
{
    public:
    void output (); // member function
    // NOTICE: you only put the function's prototype, the function implementation is to be located elsewhere (after the main () defintion)
    int month; // member variable
    int day; // member variable
    // Note that normally (by default) the member variables of a class are private
}; // Remember the required semicolon at the end of the class definition

/* ████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████ */

int main () // the main function
{
    cout << endl;

    // Declaring objects is the same as declaring a variable
    DayOfYear today, birthday; // here we declared 2 objects of class type DayOfYear
    // Objects include data (such as the member variables month and day) and operations (such as the member function output ())

    cout << "  Please enter today's date." << endl;
    cout<< "================================" << endl;
    cout << "Enter month as a number: "; // we specify this because we set the member variable month to be type integer
    cin >> today.month; // To access the class's members, you must use the class's object - we use object today to access variable month
    cout << "Enter the day of the month as a number: ";
    cin >> today.day; // To access the class's members, you must use the class's object - we use object today to access variable day
    cout << endl;

    cout << "  Please enter your birthday." << endl;
    cout<< "================================" << endl;
    cout << "Enter the month of your birthday as a number: ";
    cin >> birthday.month; // To access the class's members, you must use the class's object - we use object birthday to access variable month
    cout << "Enter the day of the month as a number: ";
    cin >> birthday.day; // To access the class's members, you must use the class's object - we use object birthday to access variable day
    cout << endl;

    cout << "Today's date is ";
    today.output (); // using object today to call class function output
    // Notice that we couldn't include today.output () with the previous line because the function output has a cout 
    // and you can't have 2 cout within each other, it will throw a compiler error
    cout << "Your birthday is ";
    birthday.output (); // using object birthday to call class function output

    if (today.month == birthday.month && today.day == birthday.day)
        cout << "\nHappy Birthday!" << endl;
    else
        cout << "\nHappy Unbirthday!" << endl;

    return 0;
}

/* ████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████ */

// Class member function definition
void DayOfYear :: output ()
// void is the function return type
// DayOfYear is the class to which this function belongs (the belonging is denoted by the scope resolution operator :: which 
// means that the function output() belongs to class DayOfYear, in other words, it instructs the compiler what class the member is from)
// output is the name of the function itself
{
    // here we write the function's body
    // this function can be used for all objects of the class, for example: today.output(); displays today object's data
    cout << day << " / " << month << endl;
}
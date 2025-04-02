# include <iostream>
using namespace std;

int main ()
{
    double decimal, afterdecimal;

    cout << "Please enter a decimal number you wish to round: ";
    cin >> decimal;

    int integer = decimal; 
    // here we are initializing an integer variable called integer and assigning to it the 
    // integer part of the double value called decimal

    afterdecimal = decimal - integer;
    // here we are extracting only the value after the decimal to check if it's greater or less than .5

    switch (afterdecimal >= 0.5) 
    // here we are switch testing a boolean expression
    // is the value stored in afterdecimal greater than or equal to 0.5?
    {
        case 1: cout << "The number has been rounded up to " << integer + 1 ; // case if the answer of the question is yes
        break;
        case 0: cout << "The number remains as " << integer; // case if the answer of the question is no
        break;
    }
}
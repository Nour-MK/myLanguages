# include <iostream>
using namespace std;

int main ()
{
    cout << "5 + 8 = " << 5 + 8 << endl;
    // Result is an integer because both numbers are integers.

    cout << "5 + 8.0 = " << 5 + 8.0 << endl;
    // Result is an integer because .0 counts as an integer in summation and subtraction

    cout << "16 - 12.5 = " << 16 - 12.5 << endl;
    // Result is double because the decimal is not .0

    cout << "2 * 2.5 = " << 2 * 2.5 << endl;
    // Result is double because one of the numbers is double

    cout << "5 / 2 = " << 5 / 2 << endl;
    // Result is an integer because both numbers are integers.

    cout << "5.0 / 2 = " << 5.0 / 2 << endl;
    // Result is double because one of the numbers is double
    // .0 in multiplication and division still counts as double

    cout << "5 / 2.0 = " << 5 / 2.0 << endl;
    // Result is double because one of the numbers is double

    cout << "34 % 5 = " << 34 % 5 << endl;
    // Modulo operator takes integers, it can't take float or double

    cout << "-34 % 5 = " << -34 % 5 << endl;
    // Modulo operator can take negative values

    cout << "5 + 2 / 3 = " << 5 + 2 / 3 << endl;
    // It will print the division result of 5 over 2/3

    cout << "(5 + 2)/3 = " << (5 + 2)/3 << endl;
    // It will print the division result of 5 + 2 = 7 over 3, the parenthesis make a different
}
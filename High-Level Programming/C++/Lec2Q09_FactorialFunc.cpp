// The factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n.

#include <iostream>
using namespace std;

int factorial (int n); // function declaration

int main () // function declaration
{
// function definition
    int num, fac;

    cout << "Enter an integer: ";
    cin >> num;
    fac = factorial (num); // function call
    cout<< "The factorial of "<< num << " is " << fac << endl; 
}

/* █████████████████████████████████████████████████████████████████████████ */

int factorial (int n) // function declaration
{
// function definition
    int i, product;
    product = 1;
    for (i = 2; i <= n; i++)
        product = product * i;
    return product;
}
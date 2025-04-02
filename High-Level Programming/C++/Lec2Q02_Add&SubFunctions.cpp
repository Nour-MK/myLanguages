/*
Write a program with two functions 
Add: Adds two integers and returns their sum
Sub: Subtracts two integers and returns the result
The details of the main function and the other two functions prototypes (parameters and return type) is up to you.
*/

#include <iostream>
using namespace std;

/* ███████████████████████████████████████████████████████████████████ */

void Add (int x, int y)
{
    cout<<"The sum of the 2 numbers is "<< x + y <<endl;
}

/* ███████████████████████████████████████████████████████████████████ */


void Sub (int x, int y)
{
    cout<<"The sub of the 2 numbers is "<< x - y <<endl;
}

/* ███████████████████████████████████████████████████████████████████ */

int main ()
{
    Add (7, 3);
    Sub (16, 8);

    return 0;
}
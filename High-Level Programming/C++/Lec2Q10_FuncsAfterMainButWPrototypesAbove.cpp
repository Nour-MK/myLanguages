#include <iostream>
using namespace std;

int getNum (); // function declaration, prototype
int larger (int a, int b); // function declaration, prototype
void outputResults (int n1, int n2, int n3); // function declaration, prototype

/* ████████████████████████████████████████████████████████████████████████████ */

int main () // function declaration
{
    // function definition
    int num1, num2, num3;

    num1 = getNum (); // function call
    num2 = getNum (); // function call
    num3 = larger (num1, num2); // function call
    outputResults (num1, num2, num3); // function call

    return 0;
}

/* ████████████████████████████████████████████████████████████████████████████ */

int getNum () // function declaration
{
    // function definition
    int value;
    cout <<"Enter an integer : ";
    cin>>value;
    return value;
}

/* ████████████████████████████████████████████████████████████████████████████ */

int larger (int a, int b) // function declaration
{
    // function definition
    if (a > b)
    return a;
    else
    return b;
}

/* ████████████████████████████████████████████████████████████████████████████ */

void outputResults (int n1, int n2, int n3) // function declaration
{
    // function definition
    cout << "Larger of "<< n1 << " and " << n2 << " is " << n3 << endl;
}
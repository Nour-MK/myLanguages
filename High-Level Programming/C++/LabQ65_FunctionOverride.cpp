# include <iostream>
using namespace std;

int cube (int n)
{
    return n*n*n;
}

/* ═════════════════════════════════════════════════════*/

double cube (double n)
// Although the 2 user-defined functions have the same
// name, their signatures still differ because of the
// return type and the parameter type
{
    return n*n*n;
}

/* ═════════════════════════════════════════════════════*/

int main ()
{
    cout << cube (4) << endl;
    // calling function cube that takes an integer-type parameter

    cout << cube (4.2) << endl;
    // calling function cube that takes a double-type parameter
}
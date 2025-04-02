#include <iostream>
using namespace std;
int factorial (int n); // function prototype

int main ()
{
    int facs[10]; // array whose elements are all integers

    for (int i = 0; i < 10; i++)
        facs [i] = factorial(i);

    for (int i = 0; i < 10; i++)
        cout << "Factorial (" << i << ") is " << facs [i] << endl;
}

/* █████████████████████████████████████████████████████████████████████████████████████ */


int factorial (int n)
{
    int i, product;
    product = 1;
    for (i = 2; i <= n; i++)
        product = product * i;
    return product;
}
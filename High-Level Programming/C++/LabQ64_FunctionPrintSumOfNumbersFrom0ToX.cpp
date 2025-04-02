# include <iostream>
using namespace std;

void sum (int x)
{
    int sum = 0;

    for (int i = 0; i <= x; i++)
    {
        sum = sum + i;
    }

    cout << "The sum of all the numbers between 0 and " << x << " = " << sum;
}

/* ═════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    int x;
    cout << "Enter a value: ";
    cin >> x;
    sum (x);
}
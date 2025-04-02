# include <iostream>
using namespace std;

void odd_even (int x)
{
    if (x%2 == 0)
    {
        cout << x << " is Even";
    }

    else 
    {
        cout << x << " is Odd";
    }
}

/* ═════════════════════════════════════════════════════════════════*/

int main ()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    odd_even (x);
}
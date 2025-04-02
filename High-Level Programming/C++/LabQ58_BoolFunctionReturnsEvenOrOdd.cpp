# include <iostream>
using namespace std;

bool odd_even (int x)
{
    if (x%2 == 0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

/* ════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (odd_even(x) == 1)
    {
        cout << x << " is Even." << endl;
    }

    else
    {
        cout << x << " is Odd." << endl;
    }
}
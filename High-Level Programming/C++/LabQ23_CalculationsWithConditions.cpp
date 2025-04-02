# include <iostream>
using namespace std;

int main ()
{
    double x, y;

    cout << "Please enter a value: ";
    cin >> x;

    if (x < 0)
    {
        y = ((x*x) - (6*x) - 1);
        cout << y;
    }

    else if (x == 0)
    {
        y = 4;
        cout << y;
    }

    else if (x > 0)
    {
        y = -x;
        cout << y;
    }
}
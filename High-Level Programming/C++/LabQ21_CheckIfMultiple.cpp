# include <iostream>
using namespace std;

int main ()
{
    int x, y;

    cout << "Please type in two numbers." << endl;
    cin >> x >> y;

    if (y % x == 0)
    {
        cout << y << " is a multiple of " << x;
    }

    else 
    {
        cout << y << " is not a multiple of " << x;
    }
}
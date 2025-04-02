# include <iostream>
using namespace std;

int max (int x, int y, int z)
{
    if ((x > y) && (x > z))
        return x;
    else if ((y > x) && (y > z))
        return y;
    else
        return z;
}

/* ════════════════════════════════════════════════════════════════════════════════════════*/

int main () // This is where the program starts executing
{
    int x, y, z;

    cout << "Enter three numbers." << endl;
    cin >> x >> y >> z;
    cout << "The max of all three numbers is " << max (x, y, z);
}
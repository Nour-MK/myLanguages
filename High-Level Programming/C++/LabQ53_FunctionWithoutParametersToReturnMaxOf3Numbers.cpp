# include <iostream>
using namespace std;

int max ()
{
    int x, y, z;
    cout << "Enter 3 numbers." << endl;
    cin >> x >> y >> z;
    // Note how we needed to include the cin in the body of the function because there's no way
    // to communicate them between the main function and this function without parameters for max

    if ((x > y) && (x > z))
        return x;

    else if ((y > x) && (y > z))
        return y;
    
    else
        return z;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    int x = max ();
    cout << "The max between the three numbers is " << x;
}
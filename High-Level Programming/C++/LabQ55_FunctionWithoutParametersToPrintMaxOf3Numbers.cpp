# include <iostream>
using namespace std;

void max ()
{
    int x, y, z;
    cout << "Enter three numbers." << endl;
    cin >> x >> y >> z;

    if ((x > y) && (x > z))
        cout << "The max between the three numbers is " << x;
    
    else if ((y > x) && (y > z))
        cout << "The max between the three numbers is " << y;

    else
        cout << "The max between the three numbers is " << z;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    max ();
}
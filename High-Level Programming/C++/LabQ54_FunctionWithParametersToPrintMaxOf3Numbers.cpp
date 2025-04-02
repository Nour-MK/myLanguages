# include <iostream>
using namespace std;

void max (int x, int y, int z)
{
    if ((x > y) && (x > z))
        cout << "The max between the three numbers is " << x;
    
    else if ((y > x) && (y > z))
        cout << "The max between the three numbers is " << y;

    else
        cout << "The max between the three numbers is " << z;
}

int main ()
{
    int x, y, z;

    cout << "Enter three numbers." << endl;
    cin >> x >> y >> z; 
    // note how there's no need to include the cin in the body of the function since we're already
    // passing the values as parameters anyway
    max (x, y, z);
}
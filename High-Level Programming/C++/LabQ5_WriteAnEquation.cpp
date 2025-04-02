# include <iostream>
using namespace std;

int main ()
{
    double x, y, w, z;
    cout << "     Enter Three Numbers"<< endl;
    cout << " =================================" << endl;
    cout << "Enter the 1st number: ";
    cin >> x;
    cout << "Enter the 2nd number: ";
    cin >> y;
    cout << "Enter the 3rd number: ";
    cin >> w;

    z = (x*y)/w;
    cout << "z = " << z << endl;

    return 0;
}
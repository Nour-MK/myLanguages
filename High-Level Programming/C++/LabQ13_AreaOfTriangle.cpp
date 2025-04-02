# include <iostream>
using namespace std;

int main ()
{
    double base, height, area;

    cout << "Please enter the base value: ";
    cin >> base;

    cout << "Please enter the height value: ";
    cin >> height;

    area = 0.5 * base * height;

    cout << "The area of the triangle is: " << area;
}
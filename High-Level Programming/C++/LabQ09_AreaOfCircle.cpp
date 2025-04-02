# include <iostream>
using namespace std;

int main ()
{
    double area, radius;

    cout << "Please enter the circle's radius: ";
    cin >> radius;

    area = 3.14 * radius * radius;

    cout << "The area is: " << area;
}
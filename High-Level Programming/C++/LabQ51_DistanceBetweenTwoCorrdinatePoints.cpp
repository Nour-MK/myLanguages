# include <iostream>
# include <cmath> // needed to use the square root function
using namespace std;

int main ()
{
    double xA, yA, xB, yB, dx, dy, distance;

    cout << "Enter the (x, y) coordinates of point A" << endl;
    cout << "x coordinate of point A: ";
    cin >> xA;
    cout << "y coordinate of point A: ";
    cin >> yA;
    cout << "Enter the (x, y) coordinates of point B" << endl;
    cout << "x coordinate of point B: ";
    cin >> xB;
    cout << "y coordinate of point B: ";
    cin >> yB;

    dx = xA - xB;
    dy = yA - yB;
    distance = sqrt(dx*dx + dy*dy);

    cout << "The distance between points A and B is = " << distance;
}
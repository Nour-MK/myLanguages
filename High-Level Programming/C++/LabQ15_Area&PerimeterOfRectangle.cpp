# include <iostream>
using namespace std;

int main ()
{
    double area, perimeter, width, length;

    cout  << "Please enter the width of the rectangle: ";
    cin >> width;
    cout << "Please enter the length of the rectangle: ";
    cin >> length;

    area = width * length;
    perimeter = 2 * (width + length);

    if (length > width) 
    // this condition makes sense as the rectangle can't have same value for both width and length or else it would be a square
    {
        cout << "The area: " << area << endl;
    }

    else
    {
        cout << "Error!" << endl << "These are not suitable dimensions for a rectangle!" << endl;
        main ();
    }

    cout << "The perimeter: " << perimeter << endl;
}
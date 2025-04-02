# include <iostream>
using namespace std;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

class point
{
    public:
    point (); // default constructor (1) - does nothing
    point (double, double); // constructor with parameters (2)
    double get_x ();
    double get_y ();
    void print ();

    private:
    double x, y;
};

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

point :: point () // remember that we must add point :: so that the compiler knows what this belongs to
{

}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

point :: point (double a, double b) // constructor 2 definition
{
    x = a;
    y = b;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

double point :: get_x ()
{
    return x;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

double point :: get_y ()
{
    return y;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void point :: print ()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

point findMiddlePoint (point T1, point T2) // this is a function that returns a class's object
// so its return type must be the type of the object which is the class, so point is the class name
// This function is not a member of class Point
{
    double midX, midY;
    midX = (T1.get_x () + T2.get_x ())/2; // proof that this function is not a member of class Point
    // is that it requires the use of an object to access member data of the class
    midY = (T1.get_y () + T2.get_y ())/2;
    point middlePoint (midX, midY); // creating object middlePoint that belongs to class Point
    return middlePoint; // return the object
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    point point1 (10, 5), point2 (-5, 5), point3; // creating 3 objects point1 and point2 and point3
    // point1 and point2 will use constructor 2, point3 will use constructor 1
    
    point3 = findMiddlePoint (point1, point2); // calling fuction and passing objects as arguments by value

    cout << "The coordinates of point1" << endl;
    point1.print(); // remember this statement can't be with the previous line because you can't
    // nest a cout inside a cout
    cout << "The coordinates of point2" << endl;
    point2.print();
    cout << "The coordinates of point3" << endl;
    point3.print();
}
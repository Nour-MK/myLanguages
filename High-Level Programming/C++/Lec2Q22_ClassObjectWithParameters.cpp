# include <iostream>
using namespace std;

class Rectangle
{
    int x, y;

    public:
    void set_values (int, int); // note how we didn't write names for the parameters, just types and it worked fine
    int area ()
    {
        return x*y;
    }
};

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

void Rectangle :: set_values (int a, int b)
{
    x = a;
    y = b;
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    Rectangle rect; // creating an object called rect that belongs to class Rectangle
    rect.set_values (3, 4); // using object rect to call the class's function set_values
    cout << "Area = " << rect.area (); // 3 * 4 = 12
}
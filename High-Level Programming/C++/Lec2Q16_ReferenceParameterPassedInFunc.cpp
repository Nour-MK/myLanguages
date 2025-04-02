#include <iostream>
using namespace std;

int main ()
{
    int x = 8;
    int y = 16;
    cout << "Before The Swap." << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    swap (x, y);
    cout << "After The Swap." << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

void swap (int &x, int &y) 
// parameters are reference which means they will change the actual value of the variables passed to them
// this function does not make a copy of the variables passed to it and applies changes on those, no this is real
{
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}
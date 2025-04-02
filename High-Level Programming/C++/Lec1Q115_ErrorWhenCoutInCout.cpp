#include <iostream>
using namespace std;

void ADD (int a, int b)
{
    cout<<a+b;
}

int main ()
{
    int x=3.5, y=5;
    // cout << ADD (x, y) <<endl; 
    // note how this causes an error because you can't put cout << cout
    // also, note that even without the cout << it would cause an error 
    // because you can't put an << endl after a void function call
}

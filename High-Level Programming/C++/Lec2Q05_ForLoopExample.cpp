#include <iostream>
using namespace std;

int main ()
{
    for (char c; c != 'n'; cin >> c) 
    // see how the increment/decrement parameter could actually be an input from the user
    {
        cout << "Do you want to continue: (y/n)" << endl;
    }
}
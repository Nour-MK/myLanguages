#include <iostream>
using namespace std;

int main ()
{
    int y;

    {
        int a = y;
        cout << a << endl; // this will print a just fine because it is within the block in which a is defined
    }

    cout << a << endl; // this will cause an error because a doesn't exist outside the previous block
}
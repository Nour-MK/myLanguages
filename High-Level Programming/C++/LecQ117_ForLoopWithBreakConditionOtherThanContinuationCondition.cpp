#include <iostream>
using namespace std;

int main ()
{
    for (int i=0; i<10; i++)
    {
        if (i==5)
        break;
        cout<<i<<" ";
    }
}

// output : 0 1 2 3 4
# include <iostream>
using namespace std;

int main ()
{
    int x = 3;
    x++; // x will increment in the next line
    cout << x << endl; // the x will have incremented by now so it will print 3
    // it will print 4 

    int y = 12;
    cout << y++ << endl << y; // this line is printing y before it increments
    // it will print 12  and the second one will print 13 because the incrementation has happened by now
}
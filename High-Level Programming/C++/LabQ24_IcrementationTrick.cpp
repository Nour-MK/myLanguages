# include <iostream>
using namespace std;

int main ()
{
    double i = 3, j = 4;

    i += j++; // means i = i + j then j will be incremented starting from the next line

    cout << "i = " << i << endl; // will print 3 + 4 = 7
    cout << "j = " << j << endl; // will print 5
}
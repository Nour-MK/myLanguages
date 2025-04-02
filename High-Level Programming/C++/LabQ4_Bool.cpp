# include <iostream>
using namespace std;

int main ()
{
    bool b = 3;
    cout << b;
    cout << endl;
    // it will print 1 even though b has value of 3
    // That is because bool only takes true or false values meaning 1 or 0

    bool z = 2;
    cout << z;
    cout << endl;
    // it will also print 1
    // only if bool takes false or 0, the number will print 0
    // any other value assigned to a boolean type even if it was negative will be true

    int x = 12;
    bool y = true;
    cout << x + y;
    cout <<endl;
    // since bool y is true then as a numerical value to the compiler it's one 1, so 1 +12 = 13
}
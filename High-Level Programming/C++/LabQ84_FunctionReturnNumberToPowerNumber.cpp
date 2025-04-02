# include <iostream>
using namespace std;

int Power (int x, int y)
{
    if (y == 0)
        return 1;
    else
        return x * Power (x, y-1);
}

/* ═══════════════════════════════════════════*/

int main ()
{
    int x = 3;
    int y = 8;

    cout << "3^8 = " << Power (x, y);
}

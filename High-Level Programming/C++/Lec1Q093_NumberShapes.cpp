/*
456
567
678
789
*/

#include <iostream>
using namespace std;

int main ()
{
    for (int row = 4; row <= 7; row ++)
        {
            for (int column = row; column <= row + 2; column++)
                {
                cout<<column;
                }
        cout<<endl;
        }

    return 0;
}

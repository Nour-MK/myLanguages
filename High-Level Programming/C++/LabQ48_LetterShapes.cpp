/*
Desired output:
ABC
BCD
CDE
DEF
*/

# include <iostream>
using namespace std;

int main ()
{
    for (char row = 'A'; row <= 'D'; row++)
    {
        for (char column = row; column <= row + 2; column++)
        {
            cout << column;
        }

        cout << endl;
    }
}
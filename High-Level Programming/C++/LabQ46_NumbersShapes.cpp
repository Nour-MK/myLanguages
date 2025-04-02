/*
Desired output:
1234
2345
3456
4567
5678
*/

# include <iostream>
using namespace std;

int main ()
{
    for (int row = 1; row <= 5; row++)
    {
        for (int column = row; column <= row+3; column++)
        {
            cout << column;
        }

        cout << endl;
    }
}
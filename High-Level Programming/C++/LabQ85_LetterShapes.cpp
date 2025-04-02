# include <iostream>
using namespace std;

int main ()
{
    for (char row = 'A'; row <= 'F'; row++)
    {
        for (char column = row; column <= row && column >= 'A'; column--) // Note the double conditions!
        {
            cout << row;
        }
        cout << endl;
    }
}
# include <iostream>
using namespace std;
void Letters (char c[6][6]);
int capital = 0; // initial counter for capital letters
int small = 0; // initial counter for small letters

int main ()
{
    char small_capital [6][6];
    cout << "Enter values to fill the 6 x 6 matrix." << endl;
    for (int row = 0; row < 6; row++)
    {
        for (int column = 0; column < 6; column++)
        {
            cin >> small_capital [row][column];
        }
    }

    Letters (small_capital);
}

/* ═══════════════════════════════════════════════════════════════════════════*/

void Letters (char c [6][6])
{
    for (int row = 0; row < 6; row++)
    {
        for (int column = 0; column < 6; column++)
        {
            if ((c[row][column] >= 'A') && (c[row][column] <= 'Z'))
            {
                capital++;
            }

            else if ((c[row][column] >= 'a') && (c[row][column] <= 'z'))
            {
                small++;
            }
        }
    }

    cout << "The number of capital letters that appear in the matrix is " << capital << endl;
    cout << "The number of small letters that appear in the matrix is " << small << endl;
}
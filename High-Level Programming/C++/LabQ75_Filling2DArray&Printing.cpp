# include <iostream>
# include <iomanip>
// needed for the set width function used below
// can read more about the library at https://cplusplus.com/
using namespace std;

int main ()
{
    int row, column;
    int matrix [5][5]; // this is a 5 x 5 matrix containing 25 elements

    // the function of these 2 nested loops is to fill each column with the row number 
    for (row = 0; row < 5; row++)
    {
        for (column = 0; column < 5; column++)
        {
            matrix [row][column] = row;
        }
    }

    // the function of these 2 nested loops is just to format the output when we print the matrix
    for (row = 0; row < 5; row++)
    {
        for (column = 0; column < 5; column++)
        {
            cout << setw (5) << matrix[row][column] << " ";
        }

        cout << endl;
    }
}
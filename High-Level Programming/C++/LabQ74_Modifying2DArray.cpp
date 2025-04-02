# include <iostream>
using namespace std;

int main ()
{
    int x [3][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}}; 
    // this is a 2 dimensional array
    // it contains 3 rows and 4 columns
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // this array contains 12 elements
    int temp;

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 4; column++) // note how we need 2 nested for loops to deal with 2D arrays
        {
            cout << x [row][column] << "\t"; // printing the values in array x
        }

        cout << endl; 
        // note how going to the next line happens at the end of the row and that is why it's in the row loop
    }

    for (int row = 0; row < 3; row++)
    // the function of this loop is exchanging column 1 with 2
    {
        temp = x[row][2];
        x[row][2] = x[row][1];
        x[row][1] = temp;
    }

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << x[i][j] << "\t"; // printing the new values in array x after the change
        }

        cout << endl;
    }
}
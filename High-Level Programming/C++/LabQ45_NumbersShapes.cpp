/*
Desired output:
1
21
321
4321
54321
*/

// This code is more complex than the previous one because now the entries are not the same thing *

# include <iostream>
using namespace std;

int main ()
{
    for (int row = 1; row <= 5; row++)
    // condition is the way it is because we want to have 5 rows
    {
        for (int column = row; column >= 1; column--)
        // condition is the way it is because we want to print the numbers in a descending order such that
        // there is a matching number of entries in a row that match the number of the row
        // We want number 1 to be the end of each row
        {
            cout << column;
        }

        cout << endl;
    }
}
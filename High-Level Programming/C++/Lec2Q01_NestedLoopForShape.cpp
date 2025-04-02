/*
Write a code using a nested loop that produces the shape below:
X
XX
XXX
XXXX
XXXXX
*/

#include <iostream>
using namespace std;
int main ()
{
    for (int row = 0; row <= 4; row++)
    {
        for (int column = 0; column <= row; column++)
        {
            cout<< "X";
        }

        cout<<endl;
    }
    return 0;
}

// The big O complexity of this code is O(n^2)
// Even thought the outer loop is running O(4) = O(1) and the inner one depends on it
// the general ides here is that for any number of rows, the number of columns will 
// run as much as the rows so it is O(n)
// Note also that O(n^2) is not actually happening; it's the worst case.
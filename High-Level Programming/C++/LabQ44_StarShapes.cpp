/*
Desired output:
*
**
***
****
*/

# include <iostream>
using namespace std;

int main ()
{
    for (int row = 1; row <= 4; row++) 
    // condition is the way it is because we want to have 4 rows
    {
        for (int column = 1; column <= row; column++) 
        // condition is the way it is because we want the number of entires in the row to match the number of the row
        {
            cout << "*";
        }

        cout << endl;
    }
}

/*
Code tracing: 
Outer loop
row = 1
condition: row <= 4? yes
Enter inner loop
column = 1
condition: column <= 1? yes
print *
column++ = 2
condition: column <= 1? no
Leave inner loop, back to outer loop
row++ = 2
condition: row <= 4? yes
Enter inner loop
column = 1
condition: column <= 2? yes
print *
column++ = 2
condition: column <= 2? yes
print **
column++ = 3
condition: column <= 2> no
Leave inner loop, back to outer loop
*/
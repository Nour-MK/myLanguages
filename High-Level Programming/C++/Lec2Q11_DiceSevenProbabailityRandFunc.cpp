/* 
In some dice games, the number 7 is particularly important.
The following is a program that uses the random number generator to simulate the throwing of 2 dice and then tests this simulation
by "throwing" the dice 1000 times and seeing how many times the dice come up 7. 
Note that with real dice there are only 6 * 6 = 36 possible throw combinations of which only 
(1, 6)
(2, 5)
(3, 4)
(4, 3)
(5, 2)
(6, 1)
are 7. Thus, there are 6 throws that come up 7 out of a total of 36 possible throws. This, with "fair" dice, 7 should occur about
6/36 = 1/6 of the time. Thus, out of 1000 throws about 1/6*1000 = 166.66 should be 7
*/

#include <iostream>
#include <cstdlib> // needed for the function prototypes of rand and srand
#include <ctime>  // needed for the function prototype of time
using namespace std;

const int NUM_THROWS = 1000; // constant global variable
int throwOneDice (); // user-defined function prototype

/* ███████████████████████████████████████████████████████████████████████████████████████████████████████████████████ */


int main ()
{
    int i, count7 = 0, number;

    srand (time (NULL)); // seed random number generator

    for (i = 0; i <= NUM_THROWS; i++)
    {
        number = throwOneDice () + throwOneDice ();
        if (number == 7) // no need for else statement. It is not a necessary syntax. This means that if the condition is satisfied the if will be
				// accessed, if not, then the code just moves on and nothing happens.
        count7++;
    }

    cout << "The number 7 came up " << count7 << " times in " << NUM_THROWS << " rolls of the dice." << endl;

    return 0;
}

/* ███████████████████████████████████████████████████████████████████████████████████████████████████████████████████ */

int throwOneDice ()
{
    return rand()%6 + 1; // 
}
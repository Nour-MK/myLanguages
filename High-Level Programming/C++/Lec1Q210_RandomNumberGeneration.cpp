#include <iostream> // for input/output operations
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std; // use the standard namespace

int main ()
{
    srand(time(0)); // seed the random number generator with the current time
    cout << rand(); // print a random number
}

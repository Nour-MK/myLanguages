# include <iostream>
using namespace std;

int main ()
{
    char message [20] = "Hello World";

    cout << message << endl;

    message [0] = 'Y'; // overwriting H with Y
    message [5] = '!'; // overwriting the space with !
    message [6] = '\0'; // overwriting the rest of the cstring with null character to signify the end of the cstring

    cout << message << endl; // printing the cstring after the modifications 
}
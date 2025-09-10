// Generate a random number that has only two digits

#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
cout<<10+rand ()%89; // generates a random number between 10-99
// I was thinking 10 and 90 numbers above it but it's actually 10 and 89 numbers above it because 90 numbers
// above 10 means 100 will be included in the possible random numbers and it can't be because it has 3 digits.
return 0;
}
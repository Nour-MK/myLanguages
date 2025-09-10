#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
cout<<rand()%5; // generates a random value between 0-4
// ^ 5 is the range but because we start counting from 0 then the max number possible is 4
// because 0 1 2 3 4 are 5 numbers
cout<<rand()%6; // generates a random value between 0-5
}
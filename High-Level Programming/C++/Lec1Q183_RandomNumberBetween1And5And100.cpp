#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
cout<<rand ()%5+1; // generates a random number between 1-5
// it's the same as saying cout<<1+rand ()%5
// the 5 is included this time because we start counting from 1
cout<<rand ()%100+1; //generates a random number between 1-100
return 0;
}
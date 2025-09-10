//Write a program that generates a random number between 29-77

First thing I should know the range by 77-29=48
And I know that the offset is 29 because it is the lowest number possible

#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
cout<<29+rand()%49;//I wrote 49 because it should be the (range+1) if I want to include the 77
return 0;
}
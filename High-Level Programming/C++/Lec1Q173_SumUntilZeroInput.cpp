// Q: Write the program that reads and calculates the sum of an unspecified
// number of integers (hint that we must use while loop cuz if-loop usage 
// depends on us knowing how many times the action will be repeated). 
// The input 0 will end the loop.

#include <iostream>
using namespace std;
int main ()
{
int x, sum=0;

do
{
cin>>x; //important note: you CAN'T put endl after cin
// you are pressing enter on the keyboard so that the computer takes the value from
// you anyway and this enter press also takes you to the second line.
sum=sum+x;
} while (x!=0);

return 0;
}
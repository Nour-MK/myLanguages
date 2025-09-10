// What's the output?

#include <iostream>
using namespace std;

void change (int x, int y=2)
{
x++;
y--;
cout<<x<<y;
}

int main ()
{
change (5); // the compiler will look for a function called change that 
// takes 1 parameter and won't find any, its next step would be to search in the code
// for a function that has 2 parameters and the second of them must be predefined
return 0;
}
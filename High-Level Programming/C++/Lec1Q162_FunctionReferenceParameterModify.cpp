// What's the output?

#include <iostream>
using namespace std;

void change (int x, int y, int &z)
{
x++;
x=x+y;
z=7;
}

int main ()
{
int x, y, z;
x=1, y=2, z=3;

change (x, y, z); //notice that the function we are calling doesn't have a cout 
// in it which means this line will not print anything,
// it's only happening in the memory of the compiler
cout<<x<<y<<z; // only z was changed because it was called by reference
return 0;
}

//127

//What's the output?

#include <iostream>
using namespace std;

void change (int x, int y=2) // y=2 is overwritten by the 6 from the main because it
// has more priority
// it makes sense because this is the same case as if it were (int x, int y) 
// since both have no value then get overwritten by the numbers in the main, so why should it
// be any different when they have pre-defined values if they are getting overwritten anyway
{
x++;
y--;
cout<<x<<y;
}

int main ()
{
change (5,6);
return 0;
}

// 65
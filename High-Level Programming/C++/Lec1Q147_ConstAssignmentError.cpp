// What's the output?

#include <iostream>
using namespace std;
const int g=6;

int main ()
{
int a=4;
g=a*2;
cout<<g<<endl;
return 0;
}

// Error, because we're assigning a value of a variable that is constant 
// (unchangable) (it's a read-only variable)
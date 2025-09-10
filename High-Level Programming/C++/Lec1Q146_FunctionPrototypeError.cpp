// What's the output?

#include <iostream>
using namespace std;
int main ()
{
myFunction ();
return 0;
}

void myFunction ()
{
cout<<"I just got executed!";
}

// Error , because the user-created function is below the main and it should be above it, at least 
// there shouldv'e been a prototype of the function at the top of the code
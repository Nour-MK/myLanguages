// What's the output?

#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
char aString [20]="WORLD";
cout<<strncpy(aString, "Hello", 3); // remember that 3 means the number of elements to be copied not the index
return 0;
}

// output : HelLD
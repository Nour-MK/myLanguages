#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
char S1 [20] = "Hello";
char S2 [20] = "Good";
cout<<strncpy (S2,S1,2); // we copy the first 2 values in S1 into S2 then the rest of S2 stays the same
}

// Heod
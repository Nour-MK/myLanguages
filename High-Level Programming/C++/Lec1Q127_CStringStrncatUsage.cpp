#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
char S1 [20] = "Hello";
char S2 [20] = "Good";
cout<<strncat (S1,S2,2); // we add only the first 2 values from S2 to S1 (WITHOUT SPACE BETWEEN THEM)
return 0;
}

// HelloGo
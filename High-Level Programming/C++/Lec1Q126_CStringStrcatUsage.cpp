#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
char S1 [20] = "Hello";
char S2 [20] = "Good";
cout<<strcat (S1,S2); // we add S2 to S1 (WITHOUT SPACE BETWEEN THEM)
return 0;
}

//HelloGood
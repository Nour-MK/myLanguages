#include <iostream>
using namespace std;
int main ()
{
char S1 [20]="Test";
char S2 [20]= "Hello";
cout<<strcpy(S1,S2); // same as saying cout S1 after copying what's inside S2 into S1
// the output will be : Hello
cout<<strncpy (S1,S2,2);
// the output will be : Hest
// note that this line won't be under the command before it. i'm answering as if it was issued separately
return 0;
}
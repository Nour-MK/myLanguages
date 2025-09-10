#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
char S1 [20] = "Hello";
char S2 [20] = "Good";
cout<<strcmp(S1,S2); //compares block by block
return 0;
}

//ASCII code of H is 072
// ASCII code of G is 071
// Therefore H-G
// 72-71=1
// output : 1

// since we already found a difference in the first index of both strings then we just print that difference and don't
// comapare the rest of the elements.
// HOWEVER, if the compiler didn't find a difference in the first index then it would move on to the next index and
// compare them and if it didn't find a difference then move on again, etc till it finds a difference or 
// ends up returning 0 after comparing all indexes and finding no difference.
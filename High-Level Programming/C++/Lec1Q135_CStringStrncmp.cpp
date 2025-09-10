// What's the output?

#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
char s1 [20]="AURAK";
char s2 [20]= "A";
cout<<strncmp (s1,s2,1);
return 0;
}

// debugging process :
start by comparing index 0 from s1 and s2, it is A in both so it moves on to the next index but s2 has no next index
so it terminates the function and return 0 because there was no difference in what elements they got to compare

// output : 0
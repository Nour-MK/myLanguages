// What's the output?

#include <iostream>
using namespace std;
int main ()
{
int b[5]={1,2,3,4,5};
for (int i=1; i<=5; i++)
cout<<b[i]<<"  ";
return 0;
}

// Unpredictable output because it would print b[1], b[2], b[3], b[4] which is 2  3  4  5
// but then the loop says i<=5 so it'll print b[5] which is an index that doesn't exist in the array 
// and it could do anything
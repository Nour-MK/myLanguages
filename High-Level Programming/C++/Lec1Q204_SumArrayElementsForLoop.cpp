// What's the output?

#include <iostream>
using namespace std;
int foo[]={2,4,6,8,10,12};
int i, result =0;

int main ()
{
for (i=0; i<5; i++)
{
result+=foo[i];
}
cout<<result;
return 0;
}

// debuggiung process :
i=0
i<5
foo has 6 elements so the max index is 5 which means the for loop will stop at index 4
2+4+6+8+10=30

// output : 30
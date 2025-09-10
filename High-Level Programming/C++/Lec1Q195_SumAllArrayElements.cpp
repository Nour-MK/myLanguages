// What's the output of this program?

#include <iostream>
using namespace std;

int main ()
{
int A[4]={4,3,0,2};
int sum=A[0];

for (int i=1; i<4; i++)
{
sum=sum+A[i];
}
cout<<sum;
return 0;
}

/* Debugging process
i=1
sum=4+3=7
i=2
sum=7+0=7
i=3
sum=7+2=9
i=4
quits loop
9
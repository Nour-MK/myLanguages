#include <iostream>
using namespace std;

int main ()
{
const int size =7;
int A[size]={1,2,3,4,5,6,7};
int sum =20;
for (int i=1; i<size; i++) // or for (int i=1; i<=size-1; i++)
{
sum=sum-A[i];
}
cout<<sum;
return 0;
}

/* Debugging process :
i=1
sum=20-2=18
i=2
sum=18-3=15
i=3
sum=15-4=11
i=4
sum=11-5=6
i=5
sum=6-6=0
i=6
sum=0-7=-7
i=7
quits loop

the output is -7*/

// The concept of a const is useful because what if I need to suddenly change the size of an array and my code had
// many for loops that utilize that array? I would have to change the size in all the loops. SO, instead of doing that
// I can make a the size const and if I need to change it then I will change it in its decalration and it'll 
// automatically get changed in all parts of the code without me having to interfere.
// What's the output?

#include <iostream>
using namespace std;
int main ()
{
int i, temp [10];
for (i=0; i<10; i++) // this loop is assigning values to each index in the array
temp [i]=2*i;
for (i=0; i<10; i=i+2) // this loop is printing the values in the array
cout<<temp[i]<<" ";
return 0;
}

/* the debugging process to better understand the question :
i=0
temp[i]=2*i
temp[0]=2*0=0
i=1
temp [1]=2*1=2
i=2
temp [2]=2*2=4
i=3
temp [3]=2*3=6
i=4
temp [4]=2*4=8
i=5
temp [6]=2*5=10
i=6
temp [6]=2*6=12
i=7
temp [7]=2*7=14
i=8
temp [8]=2*8=16
i=9
temp [9]=2*9=18
i=10
temp [10]=2*10=20
i=11
quits loop
so now we have temp[10]={0,2,4,6,8,10,12,14,16,18,20}
execute second loop
i=0
print temp[0]=0
i=0+2=2
print temp[2]=4
i=2+2=4
print temp[4]=8
i=4+2=6
print temp[6]=12
i=6+2=8
print temp[8]=16
i=8+2=10
can't enter loop as the condition is i<10
so the output is
0  4  8  12  16
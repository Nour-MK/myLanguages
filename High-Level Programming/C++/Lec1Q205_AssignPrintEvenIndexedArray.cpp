// What's the output?

#include <iostream>
using namespace std;
int main ()
{
int i, temp [10];
for (i=0;i<10;i++)
temp[i]=2*i;
for (i=0;i<10;i=i+2)
cout<<temp[i]<<" ";

return 0;
}

// debugging process :
assigning values to the array temp
temp [0]= 2*0=0
temp [1]= 2*1=2
temp [2]= 2*2=4
temp [3]= 2*3=6
temp [4]= 2*4=8
temp [5]= 2*5=10
temp [6]= 2*6=12
temp [7]= 2*7=14
temp [8]= 2*8=16
temp [9]= 2*9=18
then we print
temp [0]
i=0+2=2
temp [2]
temp [4]
temp [6]
temp [8]

// output : 0 4 8 12 16
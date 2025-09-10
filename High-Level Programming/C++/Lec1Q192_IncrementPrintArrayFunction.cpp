// What is the output?

#include <iostream>
using namespace std;
void oneMore (int a[], int size)
{
for (int index=0; index<size; index++)
{
a[index]=a[index]+1;
cout<<a[index]<<"  ";
}
}

int main ()
{
int b[5]= {1,2,3,4,5};
oneMore(b,5);
}

/* Debugging process
b[0]=1
b[1]=2
b[2]=3
b[3]=4
b[4]=5
b[5]=uninitialized
now we execute the function
index=0
a[0]=a[0]+1
a[0]=1+1
print 2
index=1
a[1]=a[1]+1
a[1]=2+1
print 3
index=2
a[2]=a[2]+1
a[2]=3+1
print 4
index=3
a[3]=a[3]+1
a[3]=4+1
print 5
index=4
a[4]=a[4]+1
a[4]=5+1
print 6
index=5
quits loop

so the output is 2  3  4  5  6
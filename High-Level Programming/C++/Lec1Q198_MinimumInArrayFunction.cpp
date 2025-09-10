// Write a funtion that finds the minimum value in an array

#include <iostream>
using namespace std;

void min (int A[], int size)
{
int min=A[0];
for (int i=1; i<size; i++)
{
if (A[i]<min)
{
min=A[i];
}
}
cout<<min;
}

int main ()
{
int A[3]={14,30,70};
min (A, 3);
return 0;
}

// 14
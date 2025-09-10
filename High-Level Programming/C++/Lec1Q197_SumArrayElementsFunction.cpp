// Write a function to calculate the additon of all the elements in an array

#include <iostream>
using namespace std;
void sum (int A[], int size)
{
int sum=A[0];
for (int i=1; i<size; i++)
{
sum=sum+A[i];
}
cout<<sum;
}

int main ()
{
    int size =6;
    int A[size]={1,2,3,4,5,6};
    sum (A, size);
}

// 21
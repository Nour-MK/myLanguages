// You cannot print all the values in an array without a loop

#include <iostream>
using namespace std;
int main ()
{
int A[20];
for (int i=0; i<20; i++)
{
cout<<A[i]<<"  ";
}

return 0;
}

// remember that if i just write cout<<A[20]; I'll get an error because there is no index 20 in my array as the
// max index in an array of 20 elements in 19 because we start counting from 0.
// So, the compiler doesn't think you're asking to print all the values in the array.
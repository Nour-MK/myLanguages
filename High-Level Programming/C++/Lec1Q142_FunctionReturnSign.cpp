// Write a function that takes one integer and returns -1 if the number is negative 
// and returns 1 if the number is positive?

#include <iostream>
using namespace std;

int sign (int a)
{
if (a>=0)
return 1;
else
return -1;
}

int main ()
{
int x;
cout<<"Please enter any value"<<endl;
cin>>x;

cout<<sign(x);
return 0;
}
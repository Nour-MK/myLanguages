// Q: Write a program to ask the user to enter 6 values, and display their addition

#include <iostream>
using namespace std;
int main()

{
int x, sum =0;
cout<<"Please enter 6 values"<<endl;
for(int i=0; i<6; i++)
{
  cin>>x;
  sum = sum + x;
}
cout<<sum;

  return 0;
}
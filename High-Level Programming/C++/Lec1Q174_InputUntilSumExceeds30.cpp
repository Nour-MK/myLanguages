// Q: Read values from the user and stop when the addition of the 
// values is greater than 30

#include <iostream>
using namespace std;
int main ()
{
int x, sum;
cout<<"Please enter values"<<endl;
cin>>x;
sum=x;

while (sum<30)
{
cin>>x;
sum=sum+x;
}
return 0;
}
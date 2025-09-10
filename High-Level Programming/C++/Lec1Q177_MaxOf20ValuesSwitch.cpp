// Q: Write a code that reads 20 values and displays their maximum

#include <iostream>
using namespace std;
int main ()
{
int x, max=0;
cout<<"Please enter 20 values"<<endl;

for (int i=0; i<20; i++)
{
cin>>x;

switch (x>max) // note that we are still inside the for loop
{
case 1 : max=x;
break;
case 0 : max=max;
break;
}

}
cout<<"The maximum number is : "<<max;

return 0;
}
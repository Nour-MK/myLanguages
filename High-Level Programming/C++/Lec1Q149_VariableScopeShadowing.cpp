// What's the output?

#include <iostream>
using namespace std;
int main ()
{
{
int x=1;
cout<<x<<"  ";
{
cout<<x<<"  ";
int x=2;
cout<<x<<"  ";
{
cout<<x<<"  ";
int x=3;
cout<<x<<"  ";
}
cout<<x<<"  ";
}
cout<<x<<"  ";
}
return 0;
}

// 1  1  2  2  3  2  1
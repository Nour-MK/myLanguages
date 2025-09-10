// What's the output?

#include <iostream>
using namespace std;

void area (int a, int b, int c)
{
cout<<a+1<<endl;
cout<<b<<endl;
cout<<c--<<endl;
}

int main ()
{
area (5.5, 4, 6); // it won't give an error, it'll just take the integer part of 5.5
return 0;
}

// 6
// 4
// 6
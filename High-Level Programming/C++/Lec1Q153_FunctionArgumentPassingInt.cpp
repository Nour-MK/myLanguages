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
area (5, 4, 6);
return 0;
}

// 6
// 4
// 6 (because it's c-- so it will execute next line but there is no next line that's why it still didn't apply)
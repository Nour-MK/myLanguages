// What's the output?

#include <iostream>
using namespace std;

void abc (int &p)
{
p=8;
cout<<p<<" ";
}

int main ()
{
int m=4;
abc(m);
cout<<m<<" ";
return 0;
}

// output : 8 8
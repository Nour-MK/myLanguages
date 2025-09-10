// What's the output?

#include <iostream>
using namespace std;
int g=10;

void func1 ()
{
g=20;
cout<<g<<"  ";
}

int main ()
{
func1 ();
g=30;
cout<<g<<"  ";
return 0;
}

// 20  30
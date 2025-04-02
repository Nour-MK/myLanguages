/*
A
AB
ABC
ABCD
*/

#include <iostream>
using namespace std;
int main ()
{
for (char r='A'; r<='D'; r++)
{
for (char c='A'; c<=r; c++)
{
cout<<c;
}
cout<<endl;
}

return 0;
}

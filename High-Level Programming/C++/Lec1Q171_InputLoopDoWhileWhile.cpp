// Q: Read values from the user and stop when they enter 2.

#include <iostream>
using namespace std;
int main ()
{
int x;

do
{
cin>>x;
} while (x!=2);

return 0;
}

// another method

#include <iostream>
using namespace std;
int main ()
{
int x;
cin>>x;
while (x!=2)
{
cin>>x;
}

return 0;
}
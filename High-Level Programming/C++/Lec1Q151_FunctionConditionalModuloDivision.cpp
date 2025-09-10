// What's the output of this program?

#include <iostream>
using namespace std;
int found (int x)
{
if (x>5)
return x%5;
else
return x/5;
}

int main ()
{
cout<<found (2)<<"  ";
cout<<found (23);
return 0;
}

// 0   3
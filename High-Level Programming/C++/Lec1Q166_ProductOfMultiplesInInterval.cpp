#include <iostream>
using namespace std;
int main ()
{

double product=1;

for (int i=16; i<=66; i++)
{
if (i%8 == 0)
cout<<i<<"  ";
product = product * i;
}

cout<<"The product of all 8 multiples is : "<<product;

return 0;
}

// the product output will be 4.16e+80 and it's normal
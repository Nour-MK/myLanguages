#include <iostream>
using namespace std;

int main ()
{
    for (int i=1; i<=90; i++) // interval between 1 and 90
    {
    if (i%9 == 0) // if the division remainder is 0 then the number is a multiple of 9
    cout<<i<<"  ";
}
}

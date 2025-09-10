// Write a function that returns the average of 4 units

#include <iostream>
using namespace std;

double avg (int a, int b, int c, int d) //it's better to make the return type double as there will be division and
// it's more accurate when you have a decimal number
{
return (a+b+c+d)/4.0;
}

int main ()
{
cout<<avg(2,3,4,5);
return 0;
}
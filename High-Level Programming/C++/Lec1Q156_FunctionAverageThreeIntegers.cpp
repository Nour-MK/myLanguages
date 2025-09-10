// Write a program that has a function that returns the average of 3 integers

#include <iostream>
using namespace std;

double avg (int a, int b, int c)
{
return (a+b+c)/3.0; // if i only wrote 3 then the result would be an integer number and we want an
// accurate decimal number since we even made the function return a double output
}

int main ()
{
cout<<avg (3, 5, 5);
return 0;
}
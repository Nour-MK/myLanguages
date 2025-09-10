// Write a program that contains a funtion which prints the area of a cube

#include <iostream>
using namespace std;

void area (double x)
{
cout<<(6*x*x);
}

int main ()
{
int side;
cout<<"Please enter the measure of the cube side : ";
cin>>side;
area (side);
return 0;
}
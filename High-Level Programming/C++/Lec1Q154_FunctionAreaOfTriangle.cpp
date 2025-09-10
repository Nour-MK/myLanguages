// Write a program that has a function that returns the area of a triangle

#include <iostream>
using namespace std;

double area (int h, int b)
{
return (b*h)/2;
}

int main ()
{
int h, b;
cout<<"Enter the base of the triangle : ";
cin>>b;

cout<<endl;
cout<<"Enter the height of the triangle : ";
cin>>h;

cout<<endl;
cout<<"The area of the triangle is "<<area (h, b);
return 0;
}
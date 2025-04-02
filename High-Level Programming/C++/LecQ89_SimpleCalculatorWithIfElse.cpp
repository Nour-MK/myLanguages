#include <iostream>
using namespace std;

int main()
{

double num1, num2;
char sign;

cout << "Enter the first number: ";
cin >> num1;
cout << "Enter the second number: ";
cin >> num2;

cout<<"Enter a sign: ";
cin>>sign;

if (sign=='+')
{
cout<<"The addition result = "<<num1+num2;
}
else if (sign=='-')
{
cout<<"The subtraction result = "<<num1-num2;
}
else if (sign=='*')
{
cout<<"The multiplication result = "<<num1*num2;
}
else if (sign=='/')
{
cout<<"The division result = "<<num1/num2;
}

return 0;
}
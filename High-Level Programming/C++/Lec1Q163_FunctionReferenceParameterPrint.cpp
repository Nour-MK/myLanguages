#include <iostream>
using namespace std;

void change (int &x) // a copy of a is created in this function and it's named x
// and its value is 3
{
x=4; // the value of x which is 3 is overwritten to 4
cout<<x<<endl;
}

int main ()
{
int a=3;
change (a); // calling the void function called change that has one parameter
cout<<a; //a is changed to 4 even though we left the function because it was call by reference
return 0;
}

// 4
// 4
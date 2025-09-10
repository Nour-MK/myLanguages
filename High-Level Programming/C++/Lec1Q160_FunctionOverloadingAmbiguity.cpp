// What's the output?

#include <iostream>
using namespace std;

void change (int x)
{
x++;
}

void change (char x) // not used in this program
{
cout<<"Hi";
}

int main ()
{
change (5.0); // this calls the function change that has a parameter of the type double
return 0;
}

//error

// the dr said it's a confusing case as some compilers 
// may take the integer part of 5.0 which is 5 and execute change (int x)
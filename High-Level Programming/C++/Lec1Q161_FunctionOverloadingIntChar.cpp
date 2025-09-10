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
change (5); // this calls the function change that has a parameter of the type integer
return 0;
}

// the output is nothing because notice that the function called didn't have a cout in it
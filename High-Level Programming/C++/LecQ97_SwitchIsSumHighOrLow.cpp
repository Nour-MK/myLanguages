#include <iostream>
using namespace std;

int main ()
{
    double num1, num2, sum;

    cout<<"Please enter 2 values"<<endl;
    cin>>num1>>num2;

    sum=num1+num2;

    switch (sum>50)
    {
    case 1 : cout<<"High"; // true
    break;
    case 0 : cout<<"Low"; // false
    break;
    }
}

/* We can't write a comparison inside the parenthesis of a case within the 
switch statement. The case can only take one item that could change. 
So, to write a comparison we must plug the comparison into the switch statement
itself and the cases would be either true or false (but in c++ lingo that 
would be 1 for true and 0 for false. */
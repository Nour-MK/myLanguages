// Q: Write a program that prints all the odd numbers from 1 to 30.

#include <iostream>
using namespace std;
int main ()
{

int i=1;

while (i<30)
{
cout<<i<<endl;
i=i+2;
}

return 0;
}

// another method

#include <iostream>
using namespace std;
int main ()
{

int i=1;

while (i<30)
{
if (i%2!=0)
{
cout<<i<<endl;
}
i++; 
//notice we put the incrementation outside the if loop and inside the while loop
// because if the condition is not satisfied then the program will never
// enter the if loop and will never increment and we will be stuck with the result 1
}

return 0;
}
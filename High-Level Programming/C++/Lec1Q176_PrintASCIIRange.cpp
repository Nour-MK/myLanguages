// Q: Print all the characters that have ASCII codes from 70 to 80

#include <iostream>
using namespace std;
int main ()
{
for(int i=70; i<=80; i++)
{
cout<<char(i)<<endl; // (char)i also works
}
return 0;
}
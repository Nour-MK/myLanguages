// ⭐ Q : What will be the output of the following code?

#include <iostream>
using namespace std;

int main()
{
  int i=10;
  if(i=20)
  cout << i ;
  return 0;
}

// 20 (because in an if statement you're supposed to be testing a 
// boolean expression but here it was just putting the value 20 in the i that 
// was previously 10, so that means you'll always enter this loop beause 
// the ondition can always be satisfied)(if the coder wanted to compare 
// they should've used double =)
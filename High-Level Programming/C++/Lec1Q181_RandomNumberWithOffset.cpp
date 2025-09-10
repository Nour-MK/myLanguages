#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
cout<<100+rand()%100; // generates a random number between 100-200
// the number before the rand is the offset; meaning it's the lowest random number possible
// the number after the rand is the range. 100 numbers after the offset
cout<<5+rand()%11; // generates a random number between 5-15
// 5 is the minimum generatable number
// count 11 numbers after 5 and you'll stop at 15
return 0;
}
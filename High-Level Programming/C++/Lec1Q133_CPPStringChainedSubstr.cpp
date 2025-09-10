// What's the output? ⭐⭐

#include <iostream>
#include <string>
using namespace std;
int main ()
{
string str ("sanfoundry.");
cout<<str.substr(3).substr(4)<<endl;
return 0;
}

// debugging process :
we are cutting the string str starting from index 3 till the end
so we end up with "foundry"
then we are cutting again on the previous cut starting from index 4 till the end
so we end up with dry

// output : dry
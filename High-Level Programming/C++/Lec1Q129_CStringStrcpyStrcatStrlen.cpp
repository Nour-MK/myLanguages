// What is the output of the following?

#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
char str1 [10]= "Hello";
char str2 [10]= "World";
char str3 [10];
int len;
strcpy (str3, str1);
strcat (str1,str2);
len = strlen(str1);
cout<<len<<endl;
return 0;
}

// debugging process:
copy str1 into str3
so now str3 = Hello
add str2 to str1
so now str1 = HelloWorld
measure the length of str1 by counting how many elements it contains (the spaces count as elements)
10 is the length of str 1
print 10

// output : 10
#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
    char a []="Hello \0 World";
    cout<<a;
}

// output : Hello
// because \0 indicates the end of a cstring and if there is something that is written after the 
// \0 then it is ignored
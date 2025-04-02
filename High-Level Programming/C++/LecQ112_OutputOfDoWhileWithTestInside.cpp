#include <iostream>
using namespace std;

int main ()
{
    int a=32;

    do
    {
        cout<<a<<" ";
        a++;
        if (a>35)
        break;
    } while (1);
}

/*
Tracing:
print 32
32++ = 33
32 > 35 ? no, don't break

print 33
33++ = 34
34 > 35 ? no, don't break

print 34
34++ = 35
35 > 35 ? no, don't break

print 35
35++ = 36
36 > 35 ? yes, break
*/
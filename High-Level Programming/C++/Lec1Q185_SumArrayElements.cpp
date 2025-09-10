#include <iostream>
using namespace std;
int foo []={2,4,6,8,10,12};
int i, result=0;

int main ()
{
for (i=0; i<5; i++)
{
result+=foo [i];
}
cout<<result;
return 0;
}

// the debugging process to better understand the ques=tion :
/*  i=0
result=result+foo[0]
result= 0+2=2
i=1
result=result+foo[1]
result=2+4=6
i=2
result=result+foo[2]
result=6+6=12
i=3
result=result+foo[3]
result=12+8=20
i=4
result=result+foo[4]
result=20+10=30
i=5
can't enter loop anymore
execute next line
print result
30  */
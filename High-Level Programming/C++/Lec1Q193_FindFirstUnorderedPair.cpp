// What's the output?

#include <iostream>
using namespace std;

int Order (double array [], int size)
{
    for (int i=0; i<size-1; i++)
    {
        if (array[i]>array[i+1])
        {
            return i;
        }
    }
    return -1; // notice that this doesn't do anything, yet the program will give error if i didn't include this line
    // it's like return 0 is the main function, it doesn't print 0 but it's essential for the proper functioning
    // even if it was return 8 still nothing would happen
}

int main ()
{
double b[5]={1,2,3,9,5};
cout<<Order(b,5)<<endl;
return 0;
}

/* Debugging process
i=0
array[0]>array[0+1]
array [0]>array [1]
1>2
No then don't do anythin
i=1
array[1]>array[1+1]
array [1]>array [2]
2>3
No then don't do anything
i=2
array[2]>array[2+1]
array [2]>array [3]
3>9
No then don't do anything
i=3
array[3]>array[3+1]
array [3]>array [4]
9>5
Yes then print 3
i=4
quit loop

so the output is 3
*/
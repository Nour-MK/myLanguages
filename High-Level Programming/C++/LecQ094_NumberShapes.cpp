#include <iostream>
using namespace std;

int main ()
{
for (int r=5; r>=1; r--)
{
    for (int c=1; c<=r; c++)
    {
        cout<<c;
    }
    cout<<endl;
}
}


/* 
output : 
12345
1234
123
12
1
*/

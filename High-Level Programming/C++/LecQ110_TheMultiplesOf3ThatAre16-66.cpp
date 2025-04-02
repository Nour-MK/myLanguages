// NOTE: Although this question is somewhat similar to the previous one in the sense
// that both are looking for the multiples of numbers, the difference here is that 
// the previous question wants the multiples of the number from 1 to 8 whereas this 
// question wants the multiples of a number in the range between 16 and 66
// (the multiple itself has to be 16 to 66, not the multiple number 16 because that's just 3*16)

// Remember that multiples of a number start by the number itself and go above

#include <iostream>
using namespace std;

int main ()
{
    int x=3, m;
    for (int i=x; i>=x; i++)
    {
        if ((i>=16) && (i<=66))
        {
            if (i%x==0)
            cout<<i<<"  ";
        }
    }
}


// Another method (Recommended by the Dr)

#include <iostream>
using namespace std;

int main ()
{
    int x = 3, m;
    for (int i = 16; i<=66; i++)
    {
        if (i%x==0)
        cout<<i<<" ";
    }
}

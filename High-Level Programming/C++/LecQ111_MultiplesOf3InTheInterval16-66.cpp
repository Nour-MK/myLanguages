// This question is different that the previous one in the sense that earlier we wanted
// to find the multiples themselves that are equal to numbers between 16 and 66
// Here, we want to find the multiples of 3 between the 16th multiple to the 66th
// i.e. 3*16, 3*17, ... 3*66

#include <iostream>
using namespace std;

int main ()
{
    int x=3, m;
    for (int i=16; i<=66; i++)
    {
        m = i * x;
        cout << m << endl;
    }
}
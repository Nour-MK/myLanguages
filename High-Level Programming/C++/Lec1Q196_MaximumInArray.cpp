// Write a program that finds the maximum in an array

#include <iostream>
using namespace std;

int main ()
{
    int A[7]={2,4,8,1,0,6,0};
    int max=A[0]; 
    // If I had assigned max=0 it would've been a flawed approach because what if the elements in my array
    // had negative numbers? Can't there be a max between negative numbers? Yes there can, then why am I assigning max=0

    for (int i=0; i<7; i++) // actually I don't need to start from int i=0 because the first index is already given to max
    // why am I comparing it again to put it in max if it's already there? It's not a mistake and it doesn't make a
    // difference but it's a bit dumb
        {
            if (A[i]>max)
            {
            max=A[i];
            }
        }
    cout<<max;
}
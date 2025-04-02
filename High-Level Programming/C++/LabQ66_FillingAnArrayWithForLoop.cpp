# include <iostream>
using namespace std;

int main ()
{
    int n[10]; // declaring an integer-filled array of size 10

    for (int i = 0; i < 10; i++)
    {
        n [i] = i + 2; // inserting integers into the empty array
        cout << n[i] << " ";
    }
}

/* 
This array with contain the following integers :
The numbers between the brackets are the elements' index in the array
n [0] = 2
n [1] = 3
n [2] = 4
n [3] = 5
n [4] = 6
n [5] = 7
n [6] = 8
n [7] = 9
n [8] = 10
n [9] = 11
*/

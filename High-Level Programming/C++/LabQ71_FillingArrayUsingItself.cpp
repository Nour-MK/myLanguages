# include <iostream>
using namespace std;

int main ()
{
    int array [5] = {4, 2}; 
    // declaring array called array of size 5 and initializing only the first 2 indexes of the array
    // this means that we still have 3 empty spots in the array to fill

    // array [0] = 4 - from declaration
    // array [1] = 2 - from declaration
    array [2] = array [1] + 1; // 2 + 1 = 3
    array [3] = array [array [1]] + 2; // array [2] + 2 = 3 + 2 = 5
    array [4] = array [3] + 6; // 5 + 6 = 11

    // so now array [5] = {4, 2, 3, 5, 11}

    for (int i = 0; i <= 4; i++)
    {
        cout << array [i] << "\t"; // printing the elements in the array
    }
}
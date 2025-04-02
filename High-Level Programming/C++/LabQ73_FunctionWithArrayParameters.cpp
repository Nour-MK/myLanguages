# include <iostream>
using namespace std;

void PrintArray (int arg[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arg[i] << " "; // printing the values of the array
    }

    cout << endl;
}

/* ════════════════════════════════════════════════════════════════════*/

int main ()
{
    int FirstArray [] = {5, 10, 15};
    int SecondArray [] = {2, 4, 6, 8, 10};

    PrintArray (FirstArray, 3);
    PrintArray (SecondArray, 5);
}
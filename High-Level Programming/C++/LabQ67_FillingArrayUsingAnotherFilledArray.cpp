# include <iostream>
using namespace std;

int main ()
{
    int x[5] = {1, 4, 6, 5, 3}; // declaring array called x of size 5 and initializing its values
    int y[5]; // declaring array called y of size 5 without initialing its values

    cout << "Array x contains: ";
    for (int i = 0; i < 5; i++) 
    // this loop's purpose is printing out the values stored in array x
    {
        cout << x[i] << " ";
    }

    cout << endl;

    cout << "Array y contains: ";
    for (int i = 0; i < 5; i++) 
    // this loop's function is assigning the values in array x to array y too then printing array y
    {
        y[i] = x [i];
        cout << y[i] << " ";
    }

    cout << endl;

    cout << "New array y contains: ";
    for (int i = 0; i < 5; i++)
    // this loop's function is overwriting the values stored in array y by assigning to it the
    // values in array x times the index of the value in the array and then printing array y
    {
        y[i] = x[i]*i;
        cout << y[i] << " ";
    }
}
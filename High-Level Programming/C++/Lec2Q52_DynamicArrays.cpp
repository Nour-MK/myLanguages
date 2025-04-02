# include <iostream>
using namespace std;

int main ()
{
    typedef double* DoublePtr; // defining a new data type for pointers called DoublePtr which creates pointers that point to data of type double
    DoublePtr d; // creating pointer d which points to data of type double
    d = new double [10]; // NOTE how the 10 is not (10) but [10] which is the operator for defining the size of arrays
    // This means that initially, we give the dynamic array d the size of 10, but we can change it later on based on our needs
    // This array is allocated dynamically at runtime so it should also be destroyed dynamically at runtime.

    d[0] = 9.9; // the first number in the array d is assigned 9.9
    *(d+1) = 4.4; // 

    cout << "d = " << d << endl; // printing the address of d[0] of array d since it's the first memory location reserved for the array
    cout << "d+1 = " << d + 1 << endl; // printing the address of the second number in the array d
    cout << "*d = " << *d << endl; // same as saying print the data of d[0]
    cout << "*(d+1) = " << *(d+1) << endl; // printing the data of d[1]
    cout << "d[1] = " << d[1] << endl;

    delete [] d; // de-allocates all memory for the dynamic array d, the brackets [] indicate that we are deleting an array
    // REMEMBER that d is still pointing to the address of d[0], so to avoid the dangling pointer, we must set d = NULL;
}
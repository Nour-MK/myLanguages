# include <iostream>
using namespace std;

typedef int* IntPointer;

void sneaky (IntPointer temp)
{
    *temp = 99;
    cout << "Inside function call *temp = " << *temp << endl;
}

int main ()
{
        IntPointer p;
        p = new int;
        *p = 77;

        cout << "Before call to function *p = " << *p << endl; // prints 77

        sneaky (p); // prints 99

        cout << "After call to function *p = " << *p << endl; // prints 99 even though the function was called by value and the value of the pointer should have reset back to 77
        // but because it's a pointer, it didn't get called by value
}
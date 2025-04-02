# include <iostream>
using namespace std;

int main ()
{
    int x = 88;
    int *Pointer1 = &x;
    int *Pointer2;

    cout << bool(Pointer1) << endl; // prints 1 (true) because Pointer1 is pointing at something
    cout << bool(Pointer2) << endl; // prints 0 (false) because Pointer2 is not pointing at anything
    // cout << *Pointer2;

    // This means that bool of a pointer returns true is the pointer is pointing and false if it's not pointing
    // In other words, the bool is like a question: Is the pointer being used?

    // NOTE: If on the computer's local compiler (not the online one) it prints 1 for the second pointer as well then this is just because the computer must make use
    // of whatever pointers it has, so if you actually print the value that it's pointing towards, you will find it's some random number, even though we didn't make it
    // point towards anything in this program.
}
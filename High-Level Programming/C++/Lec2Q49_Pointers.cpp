# include <iostream>
using namespace std;

int *p1, *p2, v1, v2; 
// p1 and p2 are pointers that point to int variables
// v1 and v2 are ordinary int variables

v1 = 0;
p1 = &v1; // setting pointer p1 to point to the address in which variable v1 is stored - in other words, p1 points to v1

// To print the data stored inside v1, you can use either of the 2 ways:
cout << v1;
cout << *p1; // the * in this case doesn't mean that p1 is a pointer, it is the dereference operator which means get the data that p1 points to
// v1 and *p1 are the same variable
// That means if we apply a change on *p1, v1 will consequently change too and vice versa

// To print the address of variable v1, you can use either of the 2 ways:
cout << &v1;
cout << p1;

// KEEP IN MIND that the address of the pointer &p1 and the address of the variable it points to, are 2 different things.

// Notice the difference :
cout << p; // prints the address that p is pointing
cout << &p; // prints the address of p itself

// At this point, you realize that giving name identifiers (like x and y) to variables is abundant since you can directly use the address of the memory location.
int *p2;
p2 = new int; // creates a new nameless variable and assigns p2 to point to it - the "new" operator creates a dynamic variable
*p2 = 9;
// Those 3 lines are one way of declaring a pointer and saving data in it without the interference of any variable

int *p3 = new int (99) // or it can be done in one line like so
// If the 99 wasn't written in the previous line and we had printed the value inside *p3 it would be 0

// Pointer variables can be assigned to one another:
https://iili.io/Hvg6OIj.png
p2 = p1; // This makes p2 point where p1 is pointing
*p2 = *p1; // This makes p2 have the same data as p1

// You can define a new type alias to eliminate the need for writing int * in each pointer declaration.
typedef int* IntPtr; 
IntPtr p; // equivalent
int *p; // equivalent
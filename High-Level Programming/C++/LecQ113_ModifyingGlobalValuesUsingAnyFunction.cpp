// Global variables can be accessed and modified by any function in C. 
// (as long as it's not declared as const)
// Global variables can only be defined before the main() function. 

#include <iostream>
using namespace std;

/* ═══════════════════════════════════════════════════════════════════════════════════════════*/

int c=12; // global // incremented to 13 by main () then incremented to 14 by test ()
void test (); // function prototype is needed above the main since its body is not defined before main

/* ═══════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    ++c; // c = 13, it modifies the global value of c, not just inside this function
    cout<<c<<" "; // print 13
    test(); // function call
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════*/

void test()
{
    ++c; // c = 14, note how function test is adding on the modification than main already made
    // this proves that the first incrementation of c in the main has changed the global value of c
    cout<<c; // print 14
}

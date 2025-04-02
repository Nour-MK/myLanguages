#include <iostream>
using namespace std;

int main ()
{
    char str[]= "Hello World!"; // defining an array of characters which is basically a cstring
    cout<<str; // note how we didn't need to print using a for loop to iterate over every index
    // this illustrates the beauty of cstrings because strings terminate with the empty 
    // character '\0', that's how it is possible for the compiler to know when a string ends 
    // even without explicitly passing its length.

    // Whereas, int arrays are normally not zero terminated. Theoretically, you could also create 
    // an int array which is zero-terminated and print that in a loop. However, the problem with 
    // zero-terminated int arrays is that the number 0 could be a meaningful value, so you cannot 
    // be sure that it really is the end of the array when you encounter that value. 
    // With strings, however, the ASCII-Code 0 does not represent a meaningful value, so you can be 
    // reasonably sure that you have reached the end of the string.
}
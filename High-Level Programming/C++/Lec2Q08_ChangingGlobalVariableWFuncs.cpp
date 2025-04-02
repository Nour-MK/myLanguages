#include <iostream>
using namespace std;

void change (); // this is a function prototype
int a = 0; // a is a global integer variable with initial value 0

int main () // the "main" function
{
    int b = 7; // if there were a global b, the global value wouldn't be used since the main function has a variable b of its own, why would it refer to find ot anywhere else
    // the global a can be used in the main since the main doesn't' have variable a of its own
		cout << "a = " << a << " b = "<< b << endl; // print to test the values before any change
    change (); // calling the function change
    cout << "a = " << a << " b = " << b << endl; // print to test the values after they have been processed in the change function
}

void change () // the user-defined function "change"
{
    int b; // this is a game changer line, if this weren't there then the compiler will throw an error because the function change () is only able to
		// access variables that are defined within its scope/body or defined globally for all functions to access and modify.
		// Thus, from this function's pov, the int b defined in the main function doesn't exist and that is why we're able to create a variable with the 
		// same name and data type without problems here. 
    b = 11; // this value doesn't get moved to the main function because it doesn't change a global variable which main will be able to read
		// note here that even if this line was changing a global variable and main has a defined variable b in its body then it would use the value in its
		// body and the global value with the adjustments made to it will be shadowed.
    a++; 
    // the global a can be used and changed in this function and it will affect the value of a in the main because the main doesn't have a variable a defined
		// in it so it takes from the global variable which this function has changed
}
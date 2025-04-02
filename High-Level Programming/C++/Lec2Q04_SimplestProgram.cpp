#include <iostream> // here we include the input/output library
// #include <iostream> means copying and pasting the code in that file to your code. 
// But if we try to use cout, endl in our code without specifying the namespace it will 
// throw an error, because these are defined in the std namespace in the iostream.

using namespace std; // needed or else the program will fail to compile
// Using namespace, you can define the context in which names are defined.
// std is an abbreviation of standard. std is the standard namespace. cout, cin and a lot of other things 
// are defined in it. 
// you have the option to call these functions (cout and cin) using std::cout and std::cin but
// including using namespace std means that you don't have to write 'std::' anymore which is more convenient.
// The keyword using technically means, use this whenever you can.
// So whenever the computer comes across cout, cin, endl or anything of that matter, it will 
// read it as std::cout, std::cin or std::endl.
// When you don't use the std namespace, the computer will try to call cout or cin as if it 
// weren't defined in a namespace (as most functions in your codes). Since it doesn't exist there, 
// the computer tries to call something that doesn't exist! Hence, an error occurs.

int main () // the main function of the program
{
    cout<<"Hello World"<<endl; // standard output stream

    // return 0; // some IDEs need this since the main function's return type is integer or else they will 
    // throw a compilation error, but some compilers are smart and don't need it to run the program correctly
}
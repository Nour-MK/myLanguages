# include <iostream>
using namespace std;

int main ()
{
    cout << "First sentence. \n";
    // The \n is a command that makes the compiler go to print on the next line

    cout << "Second sentence. \n Third sentence.";
    // Second sentence will print on the next line and third sentence will print on the line under it

    cout << "Welcome to C++" << endl;
    // Welcome to C++ will be printed on the same line as Third sentence
    // endl command makes the compiler move to the next line when printing the next coming thing

    cout << 7/2 << endl;
    // Even though the division result of 7/2 should be a decimal number, the compiler will print
    // an integer number because both numbers were written in the integer form so the compiler will
    // typecast the result to be of type integer as well

    cout << 7.0 / 2 << endl;
    // The compiler will print the division result of 7 over 2 but the result will be in double 
    // There won't be a typecast because in the question there wasn't consistency in the types

    cout << 12 << endl;
    // The compiler will print the number 12 and go to the next line

    cout << 'B' << endl;
    // The compiler will print the letter B and go to the next line

    cout << "B" << endl;
    // The compiler will also print the letter B and go to the next line
    // This is just to show that you can print the character either using double or single quotations

    cout << 3 + 2 << endl;
    // The compiler will print the result of teh addition of 3 and 2

    cout << "3 + 2" << endl;
    // The compiler will print 3 + 2 exactly as though it's a sentence 

    cout << 3 << " + " << 2 << "= " << 3 + 2;
    // The compiler will print 3 and print + and 2 and = and then print the result of of their addition

}
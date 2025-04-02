# include <iostream>
# include <string>
using namespace std;

int main ()
{
    string s;

    cout << "Type a sentence: ";

    getline (cin, s); 
    // function that belongs to string library that takes string input from the user

    cout << "The sentence you wrote is of length " << s.length() << endl;
    // function that belongs to string library that returns the length of the string

    cout << "The character at index 2 in the sentence is " << s.at(2) << endl;
    // function that belongs to string library that returns the character at index 2

    cout << "The letter a is located at index " << s.find ('a') << " in the sentence." << endl;
    // function that belongs to string library that returns the index of character a in the string
}
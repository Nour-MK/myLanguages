# include <iostream>
using namespace std;

int main ()
{
    char message1 [6] = {'H', 'e', 'l', 'l', 'o'};
    char message2 [6] = "Hello"; // this is a cstring

    cout << message1 << endl;
    cout << message2 << endl;
    cout << 'A' << endl; // this is a character
    cout << "A" << endl; // this is a string
}
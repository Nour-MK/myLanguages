# include <iostream>
using namespace std;

int main ()
{
    char ch;

    cout << "Please enter a character: ";
    cin >> ch;

    switch (ch)
    {
        case 'a':
        case 'i':
        case 'e':
        case 'o':
        case 'u':
        case 'A':
        case 'I':
        case 'E':
        case 'O':
        case 'U':
            cout << ch << " is a vowel.";
            break;
        default :
            cout << ch << " is a consonant.";
            break;
    }
}
# include <iostream>
using namespace std;

int main ()
{
    char ch;

    cout << "Enter any character: ";
    cin >> ch;

    if ((ch >= 'A') && (ch <= 'Z'))
    {
        cout << ch << " is an Uppercase Letter" << endl;
    }
    else if ((ch >= 'a') && (ch <= 'z'))
    {
        cout << ch << " is a Lowercase Letter" << endl;
    }
    else if ((ch >= '0') && (ch <= '9'))
    {
        cout << ch << " is a Digit" << endl;
    }
    else
    {
        cout << ch << " is a Special Character" << endl;
    }
}
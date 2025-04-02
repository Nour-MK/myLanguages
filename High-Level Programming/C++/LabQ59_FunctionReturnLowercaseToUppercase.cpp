# include <iostream>
using namespace std;

char LowerToUpper (char ch)
{
    return (ch-32);
}

/* ═════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    char ch;
    cout << "Enter a lowercase letter: ";
    cin >> ch;
    cout << LowerToUpper (ch);
}
# include <iostream>
using namespace std;

void LowerToUpper (char ch)
{
    cout << (char)(ch-32);
}

/* ════════════════════════════════════════════════════════════════════*/

int main ()
{
    char ch;
    cout << "Enter a lowercase letter: ";
    cin >> ch;

    LowerToUpper (ch);
}
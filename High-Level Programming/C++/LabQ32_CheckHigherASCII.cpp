# include <iostream>
using namespace std;

int main ()
{
    char a, b;

    cout << "Enter two characters: ";
    cin >> a >> b;

    if ((int)a > (int)b)
    {
        cout << a << " has a higher ASCII value than " << b;
    }

    else
    {
        cout << b << " has a higher ASCII value than " << a;
    }
}
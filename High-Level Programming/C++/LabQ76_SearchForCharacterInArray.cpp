# include <iostream>
using namespace std;

bool SearchKey (char c[], int size, char key)
{
    // the function of this loop is to check the 24 elements in the array 
    for (int i = 0; i < size; i++)
    {
        if (c[i] == key)
        {
            return 1;
        }
    }
}

/* ══════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    char c [24];
    char key;

    cout << "Enter 24 characters." << endl;
    for (int i = 0; i < 24; i++)
    {
        cin >> c[i];
    }

    cout << "Enter the character you're searching for: ";
    cin >> key;

    if (SearchKey (c, 24, key) == 1)
    {
        cout << "Your character has been found!";
    }

    else
    {
        cout << "Couldn't find your character :(";
    }
}
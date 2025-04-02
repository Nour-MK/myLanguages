# include <iostream>
using namespace std;

int main ()
{
    char ch;
    int flag = 0;

    cout << "Enter 10 Letters." << endl;
    for (int i = 1; i <= 10; i++)
    {
        cin >> ch;

        if ((ch == 'Z') || (ch == 'z'))
        {
            flag++;
        }
    }

    if (flag>0)
    {
        cout << "The character Z appeared " << flag << " times in your input." << endl;
    }

    else
    {
        cout << "The character Z did not appear in your input." << endl;
    }
}
# include <iostream>
using namespace std;

int main ()
{
    double number;

    cout << "Please enter any number: ";
    cin >> number;

    if (number >= 0)
    {
        cout << "This is a positive number!" << endl;
    }

    else
    {
        cout << "This is a negative number!" << endl;
    }
}


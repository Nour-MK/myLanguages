# include <iostream>
using namespace std;

int main ()
{
    double grade;

    cout << "Please type in your grade: ";
    cin >> grade;

    if ((grade >= 0) && (grade <= 100))
    {
        if ((grade >= 70) && (grade <= 100))
        {
            cout << "PASS!" << endl;
        }

        else
        {
            cout << "FAIL!" << endl;
        }
    }

    else
    {
        cout << "Invalid!" << endl << "Grade must be between 0 and 100." << endl;
        main ();
    }
}
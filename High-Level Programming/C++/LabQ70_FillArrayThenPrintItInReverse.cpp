# include <iostream>
using namespace std;

int main ()
{
    float Grades [10];

    cout << "Enter ten grades." << endl;

    for (int i = 0; i <= 9; i++) // fill the array
    {
        cin >> Grades[i];
    }

    for (int i = 0; i <= 9; i++) // print array in normal order
    {
        cout << Grades[i] << "\t";
    }

    cout << endl;

    for (int i = 9; i >= 0; i--) // print array in reverse order
    {
        cout << Grades[i] << "\t";
    }

}
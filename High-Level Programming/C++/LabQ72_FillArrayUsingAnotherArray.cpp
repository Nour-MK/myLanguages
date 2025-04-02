# include <iostream>
using namespace std;

int main ()
{
    int Elements [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int Values [10]; // we will fill this empty array using the values of the above array * 100

    cout << "Elements \t";
    for (int i = 0; i <= 9; i++)
    {
        cout << Elements [i] << "\t"; // printing array Elements
    }

    cout << endl;

    cout << "Values \t";
    for (int i = 0; i <= 9; i++)
    {
        Values [i] = Elements [i] * 100;
        cout << Values [i] << "\t";
    }
}
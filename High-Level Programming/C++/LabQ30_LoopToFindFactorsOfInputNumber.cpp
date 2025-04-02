// Factors of a number are lesser than it all the way to the number itself
// Multiples of an number start by the number itself and go above

# include <iostream>
using namespace std;

int main ()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "The factors of " << num << " are: ";
    for (int i = 1; i <= num; i++)
    {
        if (num%i == 0)
        {
            cout << i << " ";
        }
    }
}
# include <iostream>
using namespace std;

int main ()
{
    int i, even = 0, odd = 0;

    cout << "Enter some values." << endl;
    cout << "Enter 0 to terminate input." << endl;

    do 
    {
        cin >> i;

        if (i%2 == 0)
        {
            even++;
        }

        else
        {
            odd++;
        }
        
    } while (i != 0);

    cout << "There were " << even-1 << " even numbers in your input." << endl;
    cout << "There were " << odd << " odd numbers in your input." << endl;
}
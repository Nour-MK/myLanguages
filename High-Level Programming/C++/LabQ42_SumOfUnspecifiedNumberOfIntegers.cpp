# include <iostream>
using namespace std;

int main ()
{
    int i, sum = 0;

    cout << "Enter some values." << endl;
    cout << "Enter 0 to terminate input." << endl;

    do 
    {
        cin >> i;
        sum = sum + i;
    } while (i != 0);

    cout << "The sum of the entered numbers = " << sum;
}
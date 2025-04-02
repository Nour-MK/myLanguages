# include <iostream>
using namespace std;

int main ()
{
    int x, num, sum = 0;
    double avg;

    cout << "How many numbers do you wish to enter? ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        cout << "Enter a number: ";
        cin >> num;
        sum = sum + num;
    }

    avg = sum / x;

    cout << "Sum = " << sum << endl;
    cout << "Avg = " << avg << endl;
}
# include <iostream>
using namespace std;

int main ()
{
    int i = 0, counter = 0;
    float sum = 0, avg;

    cout << "Enter some values." << endl;
    cout << "Enter -1 to terminate input." << endl;

    while (i != -1) // -1 determines the end of the input
    {
        cin >> i;
        sum = sum + i;
        counter ++;
    }

    avg = (sum+1) / (counter-1); // to avoid including the -1 that stops the input into the calculation
    cout << "Average = " << avg << endl;
}
# include <iostream>
using namespace std;

int main ()
{
    int num, max, i = 1;

    while (i <= 20) 
    // this condition is to repeat this loop 20 times, will take 20 inputs
    {
        cout << "Enter a number: ";
        cin >> num;

        if (num > max)
        {
            max = num;
        }

        i++;
    }

    cout << "The maximum number between your input was: " << max;

}
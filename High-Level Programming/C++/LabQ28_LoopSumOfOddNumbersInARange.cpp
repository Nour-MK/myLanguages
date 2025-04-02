# include <iostream>
using namespace std;

int main ()
{
    int sum = 0;

    for (int i = 21; i <= 299; i = i+2)
    {
        sum = sum + i;
    }

    cout << "The sum of all odd numbers between 20 and 300 is: " << sum;
}
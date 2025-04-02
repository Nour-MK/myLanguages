# include <iostream>
using namespace std;

int main ()
{
    int num;

    cout << "Please type in a number: ";
    cin >> num;

    if (num % 5 == 0) 
    // Modulo operator represents the remainder of division
    // So this condition says if the remainder of dividing this number by 5 is 0 
    // then this number is perfectly divisible by 5
    {
        cout << "The number is divisible by 5." << endl;
    }

    else
    {
        cout << "The number is not divisible by 5." << endl;
    }
}
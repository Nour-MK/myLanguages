# include <iostream>
using namespace std;

int main ()
{
    int first, second, third, fourth, sum, avg;

    cout << "Enter The First Number: ";
    cin >> first;

    cout << "Enter The Second Number: ";
    cin >> second;

    cout << "Enter The Third Number: ";
    cin >> third;

    cout << "Enter The Fourth Number: ";
    cin >> fourth;

    sum = first + second + third + fourth;
    avg = sum / 4;

    cout << "The sum of the numbers is: " << sum << endl;
    cout << "The average of the numbers is: " << avg << endl;
}
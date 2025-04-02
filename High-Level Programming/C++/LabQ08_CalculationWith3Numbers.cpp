# include <iostream>
using namespace std;

int main ()
{
    double num1, num2, num3, res;

    cout << "Please enter 3 numbers: ";
    cin >> num1 >> num2 >> num3;
    // recall: when you are entering values in a row, click enter after each entered value

    res = (num1/num2) + num3;

    cout << "The result is: " << res;
}
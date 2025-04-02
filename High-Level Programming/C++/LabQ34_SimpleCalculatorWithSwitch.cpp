# include <iostream>
using namespace std;

int main ()
{
    double num1, num2;
    char sign;

    cout << "Enter the 1st number: ";
    cin >> num1;
    cout << "Enter the 2nd number: ";
    cin >> num2;
    cout << "Enter a mathematical sign: ";
    cin >> sign;

    switch (sign)
    {
        case '+' : cout << num1 << " + " << num2 << " = " << num1 + num2;
        break;
        case '-' : cout << num1 << " - " << num2 << " = " << num1 - num2;
        break;
        case '*' : cout << num1 << " * " << num2 << " = " << num1 * num2;
        break;
        case '/' : cout << num1 << " / " << num2 << " = " << num1/num2;
        break;
    }
}
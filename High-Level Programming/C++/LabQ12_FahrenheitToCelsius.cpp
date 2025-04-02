# include <iostream>
using namespace std;

int main ()
{
    double Fahrenheit, Celsius;

    cout << "Enter the Degree in Fahrenheit: ";
    cin >> Fahrenheit;

    Celsius = (Fahrenheit - 32) * 5 / 9;

    cout << "The degree in Celsius is: " << Celsius;
}
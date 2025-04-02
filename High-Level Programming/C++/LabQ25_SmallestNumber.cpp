# include <iostream>
using namespace std;

int main ()
{
    float a, b, c;

    cout << "Please enter three numbers" << endl;
    cin >> a >> b >> c;

    if ((a < b) && (a < c))
    {
        cout << a << " is the smallest number.";
    }

    else if ((b < a) && (b < c))
    {
        cout << b << " is the smallest number.";
    }

    else if ((c < a) && (c < b))
    {
        cout << c << " is the smallest number.";
    }
}
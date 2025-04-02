# include <iostream>
using namespace std;

int main ()
{
    double x, y, temp;

    cout << "Please enter the 1st number: ";
    cin >> x;

    cout << "Please enter the 2nd number: ";
    cin >> y;

    if (x > y)
    {
        temp = x; // storing the value of x somewhere (in temp) before changing its value, 
        // because once we change the value of x, its original value will be gone 
        // from the memory and we can't retrieve it to put it in y
        x = y;
        y = temp;

        cout << "The 1st number is now: " << x << endl;
        cout << "The 2nd number is now: " << y << endl;
    }

    else
    {
        cout << "No change occurred." << endl;
    }
}
#include <iostream>
using namespace std;

int main ()
{
    int value;

    cout<<"Please enter a value: ";
    cin>>value;

    if ((value>=20) && (value<=300))
    {
        cout<<"The number " << value << " is in the range from 20 to 300.";
    }

    else
    {
        cout << "The number " << value << " is not in the range from 20 to 300.";
    }

}

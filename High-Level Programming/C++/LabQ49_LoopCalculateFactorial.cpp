# include <iostream>
using namespace std;

int main ()
{
    int fact = 1, num;
    
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }

    cout << num << "! = " << fact << endl;
}
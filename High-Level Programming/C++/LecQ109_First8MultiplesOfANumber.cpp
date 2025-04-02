#include <iostream>
using namespace std;

int main ()
{
    int num, m;
    cout<<"Kindly enter a number : ";
    cin>>num;

    for (int i=1; i<=8; i++) // to find the first 8 multiples of the input number
    {
        m=i*num;
        cout<<m<<"  ";
    }
}
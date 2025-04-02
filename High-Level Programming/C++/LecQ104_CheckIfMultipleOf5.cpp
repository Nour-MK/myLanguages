#include <iostream>
using namespace std;

int main ()
{
    int num;
    cout<<"Please enter a number: ";
    cin>>num;

    if (num%5 == 0)
    cout<<num<<" is a multiple of 5";

    else
    cout<<num<<" is NOT a multiple of 5";
}
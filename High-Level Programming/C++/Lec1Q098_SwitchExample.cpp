#include <iostream>
using namespace std;
int main ()
{
    int num;

    cout<<"Please enter a number: ";
    cin>>num;

    switch (num)
    {
    case 5 : cout<<"Hi!"<<endl; // the program will only print Hi if the user inputs the number 5
    break;
    default : cout<<"Bye"<<endl;
    break;
    }
}

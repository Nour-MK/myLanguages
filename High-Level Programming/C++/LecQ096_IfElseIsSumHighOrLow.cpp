#include <iostream>
using namespace std;

int main()
{
    double num1, num2, sum;

    cout<<"Please enter 2 values"<<endl;
    cin>>num1>>num2;

    sum=num1+num2;

    if (sum>50)
    {
    cout<<"Sum is High";
    }

    else
    {
    cout<<"Sum is Low";
    }
}

// Remember that the difference between else and else if is that else doesn't take
// a condition while else if does

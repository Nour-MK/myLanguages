#include <iostream>
using namespace std;

int main ()
{
double first, second, third, Addition, Difference, Division, Average;

cout << "Please enter 1st value: ";
cin >> first;

cout << "Please enter 2nd value: ";
cin >> second;

cout << "Please enter 3rd value: ";
cin >> third;

Addition = first+second+third;
Difference = first-second-third;
Division = first/second/third;
Average = (first+second+third)/3;

cout << "The addition result is : " <<Addition<<endl;
cout << "The difference result is : " <<Difference<<endl;
cout << "The division result is : " <<Division<<endl;
cout << "The average result is : " <<Average<<endl;
}

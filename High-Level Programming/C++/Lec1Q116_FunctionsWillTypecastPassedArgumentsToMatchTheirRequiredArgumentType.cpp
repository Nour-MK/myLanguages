#include <iostream>
using namespace std;

void print (int x, int y)
{
    cout<<"x = "<<x<<" and y = "<<y; // output : x = 20 and y = 5
}

int main ()
{
    print (20.7,5); // will take only the integer part of 20.7
}

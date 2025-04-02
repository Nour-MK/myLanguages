#include <iostream>
using namespace std;

int main ()
{
    char c;
    do 
        {
            cout<< "Do you want to continue: (y/n)"<<endl;
            cin>>c;
        } while (c != 'n');
}
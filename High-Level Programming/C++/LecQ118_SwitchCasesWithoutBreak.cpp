# include <iostream>
using namespace std;

int main ()
{
    int x=2;

    switch (x)
    {
        case 1:
        cout<<"it is 1"<<endl;
        break;
        case 2:
        cout<<"it is 2"<<endl;
        default:
        cout<<"it is neither 1 nor 2"<<endl;
        break;
    }
}

/* 
output :
it is 2
it is neither 1 nor 2

because there is no break after case 2 so the compiler continues on to execute 
the next line like an idiot
*/
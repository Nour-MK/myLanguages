#include<iostream>
#include<iomanip> // needed to use the setw () function
using namespace std;

int main()
{
   int i;
   long int num;

   cout<<"Enter a number: ";
   cin>>num;

   cout<<"Multiplying (by 5) and printing the result ten times in three columns:" << endl;
   
   for(i=0; i<10; i++)
   {
      cout<<num<<setw(25)<<num<<setw(25)<<num<<"\n";
      num = num * 5;
   }
    return 0;
}

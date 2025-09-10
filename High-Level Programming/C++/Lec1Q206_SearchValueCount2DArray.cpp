// Q - Write a program that has a function to search for a certain number x in a B[4][4].
// The count how many times x appears in the array. Use the following prototype:
// void search (double B[4][4], double x);

#include <iostream>
using namespace std;

int r, c;
int flag = 0;
double v;

void search (double B[4][4], double x) // given method header
{
    
   for (int r=0; r<4; r++)
    {
        for (int c=0; c<4; c++)
        {
            if (B[r][c] == x)
            flag ++;
        }
    }

cout<<"The number "<<v<<" appeared "<<flag<<" times in the array."; 
}

//////////////////////////// just a visual divider between my methods

int main()
{
    double A [4][4];
    
 cout<<"Please enter some numbers."<<endl;
      for (r=0; r<4; r++) // rows first
    {
        for (c=0; c<4; c++)
        {
            cin>>A[r][c]; // filling in the array
        }
    }
    
 cout<<"Please enter the value you'd like to search for within all those numbers."<<endl;
 cin>>v;
 
 search (A,v); // invoking the method

    return 0;
}
#include <iostream>
using namespace std;
int main ()
{
int letter =0;
char A[6][4];
for (int r=0; r<6; r++) // rows first
{
for (int c=0; c<4; c++) // columns second
{
cin>>A[r][c];
}
if (A[r][c] == 'A') // the if statement is inside the first for loop not the second
letter ++;
}

cout<<"The ketter A appeared "<<letter<<" times in the array.";
return 0;
}
// This code does not work because I have an if statement containing [c] in the first loop when I hadn't declared
// the variable c until the second loop, so according to the first loop its an unidentified character
// this is not a big deal though, we can just seperate this test into another for loop after having used the
// first nested for loops to fill in the values of the 2-d array

#include <iostream>
using namespace std;
int main ()
{
int letter =0;
char A[6][4];
cout<<"Please write something and this program will tell you how many times the letter A has appeared in your text!"<<endl;
for (int r=0; r<6; r++) // rows first
{
for (int c=0; c<4; c++) // columns second
{
cin>>A[r][c];
}
}

for (int r=0; r<6; r++)
{
    for (int c=0; c<4; c++)
    {
        if (A[r][c] == 'A')
        letter ++;
    }
}

cout<<"The letter A appeared "<<letter<<" times in the array.";
return 0;
}

// input :
NOUR   
KIMO
ALL
TIME
ALL
DAY
EVER
// output : The letter A appeared 3 times in the array.
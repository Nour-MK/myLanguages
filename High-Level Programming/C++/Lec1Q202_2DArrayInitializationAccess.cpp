#include <iostream>
using namespace std;
int main ()
{
int A[3][5] = { {1,2,3,4,5},
                {6,7,8,9,10},
                {11,12,13,14,15} };
// it's like we made a table, horizontal are the rows and vertical are the columns, so we have 3 rows and 5 columns

// OR

//A[3][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
// this is also valid because the compiler knows its limitations. it starts filling from the first row then when
// it is full with 5 elements it automatically goes to the second row and so on.

for (int r=0; r<3; r++)
{
for (int c=0; c<5; c++)
{
cout<<A[r][c]<<"  ";
}
cout<<endl;
}

cout<<endl<<endl;

cout<<A[2][1];

return 0;
}

// output :
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15


12
// This is a program that asks the user to enter the grades of 3 hws for the same student
// Then calculates the student's average grade

#include <iostream>
using namespace std;

const int NumStudents = 10;
const int NumHW = 3;

double student_average (double g [][NumHW], int stu) 
// Notice how here we didn't need to specify the size of the first dimension so long as we included all the other sizes.
{
    double sum = 0.0;
    for (int i = 0; i < NumHW; i++)
        sum += g [stu][i];
        
    return (sum/NumHW);

    /* Another way to do it is this:

    double array_average (double a [], int len)
    {
        double sum = 0.0;
        for (int i = 0; i < len; i++)
            sum += a[i];

        if (len == 0)
            return (0);
        else
            return (sum/len); // we do this because division by 0 is a bad idea
    }
    */
}

int main ()
{
    double grades [NumStudents][NumHW]; // this is an array

    for (int i = 0; i < NumStudents; i++)
    {
        for (int j = 0; j < NumHW; j++)
        {
            cout << "Enter HW " << j << " grade for student number " << i << " : ";
            cin >> grades [i] [j];
        }
    }

    // Using student_average with grades
    for (int i = 0; i < NumStudents; i++)
        cout << "Student #" << i << " has average " << student_average (grades, i) << endl;

    /* Using array_average with grades
    for (int i = 0; i < NumStudents; i++)
        cout << "Student #" << i << " has average " << array_average (grades [i], NumHW) << endl;
    */
}
# include <iostream>
using namespace std;

int main ()
{
    float Grades [10]; // declaring array Grades of type float without initializing values
    float max = 0;

    cout << "Enter ten grades." << endl;

    for (int i = 0; i <= 9; i++) 
    // note how we cannot simply cin >> the values of an array, they must be inserted using a loop
    {
        cin >> Grades [i];
    }

    for (int i = 0; i <= 9; i++)
    // the function of this loop is to compare the values inside the array one by one against the 
    // value stored in variable max if the value of the array is greater than max then it becomes 
    // the new max
    {
        if (Grades[i] > max)
        {
            max = Grades [i];
        }
    }

    cout << "The max grade is " << max;
}
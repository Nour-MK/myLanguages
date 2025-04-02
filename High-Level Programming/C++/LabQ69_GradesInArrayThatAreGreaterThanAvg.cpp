# include <iostream>
using namespace std;

int main ()
{
    float Grades [10];
    float sum = 0;
    float avg;
    int greater_than_avg_counter = 0;

    cout << "Enter ten grades." << endl;

    for (int i = 0; i <= 9; i++)
    // the function of this loop is to take array input from the user
    // meanwhile also calculating the sum of all the taken grades
    {
        cin >> Grades [i];
        sum = sum + Grades [i];
    }

    avg = sum / 10; // function for calculating the average of 10 grades
    // BE VERY CAREFUL WITH THE PLACEMENT OF CALCULATION FUNCTIONS LIKE THIS ONE !!
    // if I had placed this right under the variable declarations after line 9
    // then the average would be calculated as 0 because sum = 0 so 0/10 = 0
    // and even though we change the value of sum later on, this one already executed
    // and will not change later on
    cout << "The average of the ten grades is " << avg << endl;

    cout << "The marks greater than the average are ";
    for (int i = 0; i <= 9; i++)
    {
        if (Grades[i] > avg)
        {
            cout << Grades[i] << " ";
            greater_than_avg_counter ++;
        }
    }
    cout << endl;

    cout << "The number of grades that were greater than the average is " << greater_than_avg_counter;
}
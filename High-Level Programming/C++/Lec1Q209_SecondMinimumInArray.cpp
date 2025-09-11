#include <iostream>
using namespace std;

int main()
{
        
    int Values[5];
    cout << "Please enter 5 values" << endl;
    
    for (int i  = 0; i < 5; i++)
    {
        cin >> Values[i];
    }
    
    int SecondCopy[5]; // the comparison tests could cause a rearrangement of the values in the array, so this array will save the original form before we do any modifications
    
        for (int i  = 0; i < 5; i++)
    {
        SecondCopy[i] = Values [i];
    }
    
    int min = Values [0];
    int min2 = Values[1];
    
    for (int i  = 2; i < 5; i++)
    {
        if (min > Values[i])
        {
            int temp = min;
            min = Values[i];
            Values[i] = temp;
        }
        
        if (min2 > Values[i])
        {
            min2 = Values[i];
        }
    }
    
    if (min < min2)
        cout << "The second minimum value is " << min2;
    
    else
        cout << "The second minimum value is " << min;
        
    // Now, to restore the original form of the array
    for (int i  = 0; i < 5; i++)
    {
        Values[i] = SecondCopy[i];
    }
    
        return 0;
}
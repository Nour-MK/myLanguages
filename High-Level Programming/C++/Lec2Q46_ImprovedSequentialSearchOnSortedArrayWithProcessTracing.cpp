# include <iostream>
using namespace std;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void SequentialSearch (int search_key, const int array [], int array_size, char sorting_type)
{
    int found = -1; // -1 means record is not found
    int comparisons = 0; // comparisons counter

    for (int pass = 0; pass < array_size; pass++)
    // pass < array size because indexing of elements starts from 0 so there isn't an element that has the same number as the array size
    {
        cout << "Compare " << search_key << " with " << array [pass] << endl; 
        comparisons++;

        if (sorting_type == 'A')
        {
            if (search_key < array [pass]) // this is the improvement condition in case the array was ascendingly sorted
            {
                cout << "Terminate search because " << search_key << " is smaller than " << array [pass] << endl;
                cout << "As the array is sorted in ascending order, " << search_key << " will certainly not be found in later entries." << endl;
                break;
            }

            else if (search_key == array[pass])
            {
                cout << "Item is found at index " << pass << endl;
                found = 1; // changing found from -1 (not found) to 1 (found)
                break; // exit the loop if the search key is found, no need to continue
            }

            else
            {
                cout << "No match." << endl;
            }
        }

        else if (sorting_type == 'D')
        {
            if (search_key > array [pass]) // this is the improvement condition in case the array was descendingly sorted
            {
                cout << "Terminate search because " << search_key << " is greater than " << array [pass] << endl;
                cout << "As the array is sorted in descending order, " << search_key << " will certainly not be found in later entries." << endl;
                break;
            }

            else if (search_key == array[pass])
            {
                cout << "Item is found at index " << pass << endl;
                found = 1; // changing found from -1 (not found) to 1 (found)
                break; // exit the loop if the search key is found, no need to continue
            }

            else
            {
                cout << "No match." << endl;
            }
        }
    }

    if (found == 1)
    {
        cout << "Search is successful!" << endl;
        cout << "Number of comparisons: " << comparisons << endl;
    }

    else
    {
        cout << "Search is unsuccessful." << endl;
        cout << "Number of comparisons: " << comparisons << endl;
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    int size;
    cout << "What is the size of your array? ";
    cin >> size;

    char sorting_type;
    cout << "Type 'A' if your array is sorted in ascending order." << endl;
    cout << "Type 'D' if your array is sorted in descending order." << endl;
    cin >> sorting_type;

    int array [size]; 
    cout << "Fill in the array with values." << endl;
    for (int index = 0; index < size; index++)
    {
        cin >> array [index];
    }

    for (int index = 0; index < size; index ++) 
    // loop to print the items in the array with their corresponding index
    {
        cout << "The element at index " << index << " is " << array [index] << endl;
    }

    int search_key;
    cout << "Which item of the array would you like to search for? ";
    cin >> search_key;

    SequentialSearch (search_key, array, size, sorting_type); 
    // calling function with the search key, array as the array name, 5 as the array size
}
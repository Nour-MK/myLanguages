# include <iostream>
using namespace std;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void BinarySearch (int search_key, const int array [], int array_size, char sorting_type)
{
    bool found = false;
    int index = -1; // -1 means record not found
    int middle;
    int left = 0; // beginning of the array
    int right = array_size-1; // end of the array
    int comparisons = 0; // comparisons counter

    while ((left <= right) && (!found))
    // left less than right condition is to make sure there are items in the sub-array to search through
    // the not found condition is to make sure the item is not found because otherwise why are you still looking for what you already found
    // This while loop acts as our recursive call
    {
        middle = (left + right)/2; 
        // dividing the index of the sum of left and right over 2 to get the middle index
        cout << "Middle index is " << middle << " with item " << array [middle] << endl;
        cout << "Compare " << search_key << " with " << array [middle] << endl;
        comparisons++;

        if (sorting_type == 'A') // the searching technique if the array is sorted ascendingly
        {
            if (array [middle] == search_key) // this is the base (terminal case) 
            // because it sets the found to true which means the loop will not continue to go on after this
            {
                index = middle;
                found = true;
                cout << "Item " << search_key << " is found at the index of  " << index << endl;
            }

            else if (array [middle] > search_key) // This condition is the whole difference between the ascending and descending order
            {
                right = middle - 1;
                cout << search_key << " is less than " << array [middle] << " so the search will be refocused on the left sub-array ( ";
                // search is refocused on the left side of the list by shifting the right (aka the end of the array) to be before the middle 
                for (int index = left; index <= right; index ++) // loop to print array
                {
                    cout << array [index] << " ";
                }
                cout << ")" << endl;
            }

            else
            {
                left = middle + 1;
                cout << search_key << " is greater than " << array [middle] << " so the search will be refocused on the right sub-array ( ";
                // search is refocused on the right side of the list by shifting the left (aka the beginning of the array) to be after the middle
                for (int index = left; index <= right; index ++) // loop to print array
                {
                    cout << array [index] << " ";
                }
                cout << ")"<< endl;
            }
        }

        else if (sorting_type == 'D') // the searching technique if the array is sorted descendingly
        {
            if (array [middle] == search_key)
            {
                index = middle;
                found = true;
                cout << "Item " << search_key << " is found at the index of  " << index << endl;
            }

            else if (array [middle] < search_key) // This condition is the whole difference between the ascending and descending order
            {
                right = middle - 1;
                cout << search_key << " is greater than " << array [middle] << " so the search will be refocused on the left sub-array ( ";
                // search is refocused on the left side of the list by shifting the right (aka the end of the array) to be before the middle 
                for (int index = left; index <= right; index ++) // loop to print array
                {
                    cout << array [index] << " ";
                }
                cout << ")" << endl;
            }

            else
            {
                left = middle + 1;
                cout << search_key << " is less than " << array [middle] << " so the search will be refocused on the right sub-array ( ";
                // search is refocused on the right side of the list by shifting the left (aka the beginning of the array) to be after the middle
                for (int index = left; index <= right; index ++) // loop to print array
                {
                    cout << array [index] << " ";
                }
                cout << ")"<< endl;
            }
        }
    }

    if (left > right)
    {
        cout << "No items left in the array." << endl;
    }

    if (found == true)
    {
        cout << "Search is successful!" << endl;
        cout << "Number of comparisons: " << comparisons << endl;
    }

    else
    {
        cout << "Item is not found." << endl;
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
    cout << "Fill in the sorted array with values." << endl;
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

    BinarySearch (search_key, array, size, sorting_type);
}
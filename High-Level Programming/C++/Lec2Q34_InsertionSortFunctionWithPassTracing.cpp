// YouTube Video visualization of the process: 
// https://youtu.be/EdIKIf9mHk0?list=PLOmdoKois7_FK-ySGwHBkltzB11snW7KQ

# include <iostream>
using namespace std;
 
void InsertionSort (int data [], int size)
{
    int item, pass, insertIndex;
    int Comparisons_counter = 0;
    int Swaps_counter = 0;

    for (pass = 1; pass < size; pass++)
    {
        cout << "Pass no. " << pass << endl;

        item = data [pass]; // aka data [insertIndex]
        insertIndex = pass;

        int Pass_comparisons = 0;
        int Pass_swaps = 0;

        cout << "Sorted list is " << data [insertIndex - 1] << " and everything to its left." << endl;
        cout << "Unsorted list is " << item << " and everything to its right." << endl;
        cout << "Item to be inserted into the sorted list is " << item << endl << endl;

        while (insertIndex > 0)
        {
            cout << "Compare " << item << " with " << data [insertIndex - 1] << " to see where it must be placed." << endl;
            Comparisons_counter++;
            Pass_comparisons++;

            if (data [insertIndex - 1] > item)
            {
                cout << "Swap " << item << " and " << data [insertIndex - 1] << endl;
                Swaps_counter++;
                Pass_swaps++;
            }

            else 
            {
                cout << "No swap." << endl;
            }

            insertIndex--;
        }

        insertIndex = pass; // since the previous while loop modified the value of insertIndex
        // this is a restatement of the value that should be inside insertIndex so that we can
        // use it again in the following while loop

        cout << endl;

        while ((insertIndex > 0) && (data [insertIndex - 1] > item))
        {
            data [insertIndex] = data [insertIndex - 1];
            insertIndex--;
        }

        data [insertIndex] = item; // insert item at the right place


        cout << "List after pass " << pass << ": ";
        for (int i = 0; i < size; i++) // for loop to print the list
        {
            cout << data[i] << " ";
        }
        cout << endl;
        cout << "Comparisons occurred in pass: " << Pass_comparisons << endl;
        cout << "Swaps occurred in pass: " << Pass_swaps << endl;
        cout << "=====================================" << endl;
    }

    cout << "Ascending Sorted list: ";
    for (int index = 0; index <8; index++) // printing the array
    {
        cout << data [index] << "  ";
    }
    cout << endl;
    cout << "Total Passes: " << pass-1 << endl;
    // We put pass - 1 because pass is incrementing in a for loop which means in the last
    // round it increments and tests the condition it fails and doesn't enter the loop so
    // the pass is uselessly incremented and the array actually took pass - 1 passes to 
    // get completely sorted

    cout << "Total Comparisons: " << Comparisons_counter << endl;
    cout << "Total Swaps: " << Swaps_counter << endl;
    cout << "=====================================" << endl;

}

int main ()
{
    int data [] = {3, 7, 4, 9, 5, 2, 6, 1};

    cout << endl;
    cout << "Original list: ";
    for (int index = 0; index <8; index++) // printing the array
    {
        cout << data [index] << "  ";
    }
    cout << endl;
    cout << "Size of the list: " << sizeof(data)/sizeof(data[0]) << endl;
    cout << "=====================================" << endl;

    InsertionSort (data, 8); // note how we passed array data without [] after its name
}
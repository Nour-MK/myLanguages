# include <iostream>
using namespace std;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void swap (int &x, int &y) // must be pass by reference so the change applies in other functions
// to swap the largest value with the item at the last index of the array
{
    int temp = x;
    x = y;
    y = temp;
}
 
/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void SelectionSort (int Data [], int size)
{
    int pass = 0, Comparisons_counter = 0, Swaps_counter = 0;;

    for (int lastIndex = size-1; lastIndex >= 1; lastIndex--) // loop 1
    // last is the index of the last item in the array of items yet to be sorted
    // note that it's more convenient for us to do the loop based on the last index but it can
    // also start from the first, it'll just be a different approach and skeleton to the function
    {
        int Pass_comparisons = 0, Pass_swaps = 0; // note that the scope in which these variables are defined
        // that means they are undefined outside of this for loop
        // we need them to separate the total comparisons and swaps that occurred during the whole 
        // sorting process from the number of comparisons ans swaps that occur in a single pass

        pass++;
        cout << "Pass no. " << pass << endl;

        int largestNumberIndex = 0; // largest item is assumed to be at the start of the array

        for (int index = 1; index <= lastIndex; index++) // loop 2 to compare and find the largest index
        {
            cout << "Compare " << Data [largestNumberIndex] << " and " << Data [index] << endl;
            Comparisons_counter++;
            Pass_comparisons++;

            if (Data[index] > Data[largestNumberIndex])
            {
                largestNumberIndex = index; // now largestIndex becomes the index of the true largest item found
            }
        }

        cout << "Largest item in the list is " << Data[largestNumberIndex] << " with index " << largestNumberIndex << endl;
        cout << "Last item in the list is " << Data[lastIndex] << " with index " << lastIndex << endl;

        if (largestNumberIndex != lastIndex) // the condition that improves the efficiency of the algorithm
        {
            cout << "Swap " << Data [largestNumberIndex] << " with " << Data [lastIndex] << endl;
            Swaps_counter++;
            Pass_swaps++;
            swap (Data[largestNumberIndex], Data[lastIndex]); // function call
        }

        else 
        {
            cout << "No swap." << endl;
        }

        cout << "List after pass " << pass << ": ";
        for (int i = 0; i < size; i++) // for loop to print the list
        {
            cout << Data[i] << " ";
        }
        cout << endl;
        cout << "Comparisons occurred in pass: " << Pass_comparisons << endl;
        cout << "Swaps occurred in pass: " << Pass_swaps << endl;
        cout << "=====================================" << endl;
    }

    cout << "Ascending Sorted list: ";
    for (int index = 0; index <6; index++) // printing the array
    {
        cout << Data [index] << "  ";
    }
    cout << endl;
    cout << "Total Passes: " << pass << endl;
    cout << "Total Comparisons: " << Comparisons_counter << endl;
    cout << "Total Swaps: " << Swaps_counter << endl;
    cout << "=====================================" << endl;

}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    int data [] = {27, 16, 1, 9, 37, 38};

    cout << endl;
    cout << "Original list: ";
    for (int index = 0; index <6; index++) // printing the array
    {
        cout << data [index] << "  ";
    }
    cout << endl;
    cout << "Size of the list: " << sizeof(data)/sizeof(data[0]) << endl;
    cout << "=====================================" << endl;

    SelectionSort (data, 6); // note how we passed array data without [] after its name
}
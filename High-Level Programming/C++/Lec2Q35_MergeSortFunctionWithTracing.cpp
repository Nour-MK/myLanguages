// YouTube Video visualization of the process: 
// https://youtu.be/dENca26N6V4?list=PLOmdoKois7_FK-ySGwHBkltzB11snW7KQ

# include <iostream>
using namespace std;

const int Max_Size = 6; // global variable containing the maximum number of items in the array

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void Merge (int data [], int first, int mid, int last)
// This function compares an item from the second half of the array to the first half
// Then it moves the smaller item into a temporary array and the remaining items are
// simply moved to the temporary array and finally the temporary array is copied back
// into the original array
{
    int TempArray [Max_Size]; // initialize a temporary array

    int first1 = first; // first sub-array begin
    int last1 = mid; // first sub-array end

    int first2 = mid + 1; // second sub-array begin
    int last2 = last; // second sub-array end

    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); index++)
    // This loop finds whether the smaller item is in the first sub-array or the second
    // Then it moves that smaller item into the temporary array
    // It continues on with all the indexes till there are no more items in the sub-arrays to compare
    {
        if (data[first1] < data[first2]) // if the smaller item is in the first sub-array
        {
            TempArray[index] = data[first1];
            first1++;
        }

        else // if the smaller item is in the second sub-array
        {
            TempArray[index] = data[first2];
            first2++;
        }
    }

    for (; first1 <= last1; first1++, index++) 
    // Note how the first parameter of the for loop is empty
    // This is the for loop syntax when the programmer doesn't wish to initialize variable
    // Move the remaining items of first sub-array into the temporary array
    {
        TempArray[index] = data[first1];
    }

    for (; first2 <= last2; first2++, index++)
    // Move the remaining items of the second sub-array into the temporary array
    {
        TempArray[index] = data[first2];
    }

    for (index = first; index <= last; index++)
    // Copies the resultant temporary array back into the original array
    {
        data[index] = TempArray[index];
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void MergeSort (int data [], int first, int last)
// This is a recursive function that divides the array into pieces until each piece contains 
// only one item and then it calls the merge function that will sort and merge them back together
{        

    if (first < last)
    {
        int mid = (first + last)/2; // to determine the index of the midpoint
        cout << "The midpoint index is " << mid << " with item " << data[mid] << endl;

        // Divide the array into halves:
        // Left half from first index till midpoint
        // Right half from after the midpoint till the end of the array

        cout << "Left Half from midpoint " << data[mid] << ": ";
        for (int index = first; index <= mid; index++) // printing the array
        {
            cout << data [index] << " ";
        }
        cout << endl;

        cout << "Right Half from midpoint " << data[mid] << ": ";
        for (int index = mid + 1; index <= last; index++) // printing the array
        {
            cout << data [index] << " ";
        }
        cout << endl;

        cout << "=============================================" << endl;

        cout << "Dividing the left half into smaller pieces." << endl;
        MergeSort (data, first, mid); // recursive call - create left half


        cout << "Dividing the right half into smaller pieces." << endl;
        MergeSort (data, mid + 1, last); // recursive call - create right half

        Merge (data, first, mid, last); // function call - sort merge the two halves

        cout << "Sorted and Merged List: ";
        for (int index = 0; index <6; index++) // printing the array
        {
            cout << data [index] << "  ";
        }
        cout << endl;
        cout << "=============================================" << endl;
    }

    else
    {
        cout << "No more items in the array to divide." << endl;
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    int data [] = {38, 16, 27, 39, 12, 27};

    cout << endl;
    cout << "Original list: ";
    for (int index = 0; index <6; index++) // printing the array
    {
        cout << data [index] << "   ";
    }
    cout << endl;
    cout << "List  indexes: ";
    for (int index = 0; index <6; index++) // printing the array indexes
    {
        cout << index << "    ";
    }
    cout << endl;    
    cout << "Size of the list: " << sizeof(data)/sizeof(data[0]) << endl;
    cout << "=============================================" << endl;

    MergeSort (data, 0, 5); // note how we passed array data without [] after its name
    // 0 is the number of the first index
    // 5 is the number of the last index

    cout << "Final Ascending Sorted list: ";
    for (int index = 0; index <6; index++) // printing the array
    {
        cout << data [index] << "  ";
    }
    cout << endl;
    cout << "=============================================" << endl;
}
// YouTube Video visualization of the process: 
// https://youtu.be/kDgvnbUIqT4?list=PLOmdoKois7_FK-ySGwHBkltzB11snW7KQ

# include <iostream>
using namespace std;

int partition (int data [], int first, int last)
// A function that organizes data so that the items with values less than pivot or equal
// to pivot will be on the left of the pivot while the values greater than pivot are to the right
{
    int pivot, temp, loop, cutPoint, bottom, top;

    pivot = data[first]; // identifying the pivot as the item in the first index of the array
    bottom = first;
    top = last;
    loop = 1; // always true

    while (loop)
    {
        while (data[top] > pivot)
        {
            // from top find values that are smaller than pivot
            top--; // because this is the end of the array, there is nothing after it so to
            // move to where there are values you must decrement to go back
        }

        while (data[bottom] < pivot)
        {
            // from bottom find values that are greater than pivot
            bottom++; // because this is the beginning of the array, there is nothing before it
            // so to move forward where there are values you must increment
        }

        if (bottom < top)
        {
            // swapping the pivot's place
            temp = data [bottom];
            data[bottom] = data[top];
            data[top] = temp;
        }

        else 
        {
            loop = 0; // always false
            cutPoint = top; // stop loop
        }
    }

    return cutPoint;

}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void QuickSort (int data [], int first, int last)
// A recursive function that will partition the array into several sub-arrays until
// there is only one item left in the sub-array
{
    int cut;

    if (first < last)
    // This condition is to make sure there are still items left in the array to divide
    {
        cut = partition (data, first, last); // function call
        cout << "Choose pivot value as the first item in the array: " << data[cut] << endl;

        cout << "Rearrange the array." << endl;
        cout << "Everything less than the pivot to its left." << endl;
        cout << "Everything greater than the pivot to its right." << endl;
        for (int index = first; index <= last; index++) // printing the array
        {
            cout << data [index] << " ";
        }
        cout << endl;

        cout << "Left half from pivot: ";
        for (int index = first; index <= cut; index++) // printing the array
        {
            cout << data [index] << " ";
        }
        cout << endl;

        cout << "Right half from pivot: ";
        for (int index = cut + 1; index <= last; index++) // printing the array
        {
            cout << data [index] << " ";
        }
        cout << endl;

         cout << "==============================================" << endl;

        // cut the array into 2 sub-arrays based on the cut value
        cout << "Divide left half." << endl;
        QuickSort (data, first, cut); // recursive call
        cout << "Divide right half." << endl;
        QuickSort (data, cut + 1, last); // recursive call
    }

    else
    {
        cout << "No more items in the array to divide." << endl;
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    int data [5] = {100,12,3,42,5};

    cout << endl;
    cout << "Original list: ";
    for (int index = 0; index <5; index++) // printing the array
    {
        cout << data [index] << "   ";
    }
    cout << endl;
    cout << "List  indexes: ";
    for (int index = 0; index <5; index++) // printing the array indexes
    {
        cout << index << "    ";
    }
    cout << endl;    
    cout << "Size of the list: " << sizeof(data)/sizeof(data[0]) << endl;
    cout << "=============================================" << endl;

    QuickSort (data, 0, 4); 
    // note how we passed array data without [] after its name
    // 0 is the number of the first index
    // 5 is the number of the last index

    cout << "Final Ascending Sorted list: ";
    for (int index = 0; index <5; index++) // printing the array
    {
        cout << data [index] << "  ";
    }
    cout << endl;
    cout << "=============================================" << endl;
}
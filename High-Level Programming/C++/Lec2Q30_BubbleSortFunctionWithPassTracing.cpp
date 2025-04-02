// YouTube Video visualization of the process: 
// https://youtu.be/semGJAJ7i74?list=PLOmdoKois7_FK-ySGwHBkltzB11snW7KQ

# include <iostream>
using namespace std;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

// this function sorts items of an array into an ascending order
void BubbleSort (int data [], int listSize) 
// note how we must always specify the size of the array in the parameter, not doing that is dangerous
{
    int pass, tempValue, Comparisons_counter = 0, Swaps_counter = 0;

    for (pass = 1; pass < listSize; pass++) // is used to control the number of passes needed
    {
        cout << "Pass no. " << pass << endl;

        for (int x = 0; x < listSize - pass; x++) 
        // is used to compare adjacent elements and swap them if they are not in order
        // moves the largest elements to the end of the array
        {
            cout << "Compare " << data [x] << " and " << data [x + 1] << endl;
            Comparisons_counter++;

            if (data [x] > data [x + 1]) // to compare the adjacent elements, sort in ascending order
            {
                cout << "Swap " << data [x] << " with " << data [x + 1] << endl;
                Swaps_counter++;

                tempValue = data [x];
                data [x] = data [x + 1];
                data [x + 1] = tempValue;

                cout << "Array after Swap: ";
                for (int i = 0; i < listSize; i++) 
                {
                    cout << data[i] << " ";
                }
                cout<< endl;
            }

            else 
            {
                cout << "No swap." << endl;
            }
        }

        cout << "==================================================" << endl;

    }

    cout << "Ascending sorted list: ";
    for (int index = 0; index < 5; index++) // printing the array
    {
        cout << data [index] << "  ";
    }
    cout << endl;
    cout << "Total Comparisons: " << Comparisons_counter << endl;
    cout << "Total Swaps: " << Swaps_counter << endl;
    cout << "==================================================" << endl;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/
 
int main ()
{
    int data [] = {7, 8, 3, 1, 6};

    cout << endl;
    cout << "Original list: ";
    for (int index = 0; index <5; index++) // printing the array
    {
        cout << data [index] << "  ";
    }
    cout << endl;
    cout << "Size of the list: " << sizeof(data)/sizeof(data[0]) << endl;
    cout << "==================================================" << endl;

    BubbleSort (data, 5); // note how we passed array data without [] after its name

}

/*
Pass = 1
List size = 5
Comparison: (7 & 8) = no swap → [7, 8, 3, 1, 6]
Comparison: (8 & 3) = do swap → [7, 3, 8, 1, 6]
Comparison: (8 & 1) = do swap → [7, 3, 1, 8, 6]
Comparison: (8 & 6) = do swap → [7, 3, 1, 6, 8] // final list of pass 1
Note: The largest element is now at the correct position. It won’t be used in future comparisons.

Pass = 2
Comparison: (7 & 3) = do swap → [3, 7, 1, 6, 8]
Comparison: (7 & 1) = do swap → [3, 1, 7, 6, 8]
Comparison: (7 & 6) = do swap → [3, 1, 6, 7, 8] // final list of pass 2
Note: The largest 2 elements are now at their correct positions. They won’t be used in future comparisons.

Pass = 3
Comparison: (3 & 1) = do swap → [1, 3, 6, 7, 8]
Comparison: (3 & 6) = no swap → [1, 3, 6, 7, 8] // final list of pass 3
Note: The largest 3 elements are now at their correct positions. They won’t be used in future comparisons. 
In reality, the whole list is now sorted but the compiler doesn’t see this, so it will actually continue to compare.

Pass = 4
Comparison: (1 & 3) = no swap → [1, 3, 6, 7, 8] // final list of pass 4
Note: The largest 4 elements are now at their correct positions. They won’t be used in future comparisons. 
Now, since the list doesn’t have a sufficient number of elements to compare (only 1 element is left, 
nothing to compare it against) then the program will stop here.

Total comparisons: 10
Total swaps: 7

Formula to prove we reached the correct number of comparisons: (n-1) + (n-2) + … and n(n-1)/2 and O(n2)
List size = 5 = n
(5 – 1) + (5 – 2) + (5 – 3) + (5 – 4) = 4 + 3 + 2 + 1 = 10
5(5-1)/2 = 10

List in worst case scenario: [8, 7, 6, 3, 1]
List in best case scenario: [1, 3, 6, 7, 8]
*/
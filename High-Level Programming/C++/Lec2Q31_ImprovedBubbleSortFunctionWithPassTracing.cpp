# include <iostream>
using namespace std;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void ImprovedBubbleSort (int data [], int size)
{
    int temp, Comparisons_counter = 0, Swaps_counter = 0;
    bool sorted = false; 
    // false is the case when swaps occur, so, at the beginning, we assume the list to be unsorted
    // this is the game-changing variable flag, it will be used to signal whether a swap occurred during the pass
    // In the external loop, it is set to true, and if there is a swap, the inner loop will set it to false
    // Another pass will continue if the sorted is false
    // Passes will stop is sorted is true

    for (int pass = 1; (pass < size) && (!sorted); pass++) // outer loop
    {
        sorted = true; // assume sorted
        cout << "Pass no. " << pass << endl;

        for (int index = 0; index < size - pass; index++) // inner loop
        {
            cout << "Compare " << data [index] << " and " << data [index + 1] << endl;
            Comparisons_counter++;

            if (data [index] > data [index + 1]) 
            // sign is > meaning that we are sorting in descending order because we swap when 
            // the left is greater than right because we want the bigger number on the right
            {
                // swapping the adjacent list elements
                cout << "Swap " << data [index] << " with " << data [index + 1] << endl;
                Swaps_counter++;

                temp = data [index];
                data [index] = data [index + 1];
                data [index + 1] = temp;

                cout << "Array after Swap: ";
                for (int i = 0; i < size; i++) 
                {
                    cout << data[i] << " ";
                }
                cout<< endl;

                sorted = false; 
                // to signal that we did a swap and assume that the list may still not be sorted
            }

            else 
            {
                cout << "No swap." << endl;
            }

        }

        cout << "==================================================" << endl;
    }

    cout << "Ascending sorted list: ";
    for (int index = 0; index < 6; index++) // printing the array
    {
        cout << data [index] << " ";
    }
    cout << endl;
    cout << "Total Comparisons: " << Comparisons_counter << endl;
    cout << "Total Swaps: " << Swaps_counter << endl;
    cout << "==================================================" << endl;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    int data [] = {27, 16, 1, 9, 37, 38}; // 55, 17, 22, 38, 13, 90

    cout << endl; // just to stay away from the execution blab of the compiler
    cout << "Original list: ";
    for (int index = 0; index <6; index++) // printing the array
    {
        cout << data [index] << "  ";
    }
    cout << endl;
    cout << "Size of the list: " << sizeof(data)/sizeof(data[0]) << endl;
    // Dividing the total amount of memory by the size of one element to obtain the size of the array
    cout << "==================================================" << endl;
    // double endline to stay away from the next list printing as a visual divider

    ImprovedBubbleSort (data, 6);
}
 
/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

/*
Code tracing:
List: [55, 17, 22, 38, 13, 90]

set Pass = 1
List size = 6
set Sorted = false
Outer Loop Condition 1: (Pass < Size) = (1 < 6) = true
Outer Loop Condition 2: (!Sorted) = (!False) = true
Enter Outer Loop because both conditions are true
set Sorted = true
set Index = 0
Inner Loop Condition: (Index < Size - Pass) = (0 < 6 - 1) = (0 < 5) = true
Enter Inner Loop
If Condition for Swapping: (index 0 > index 1) = (55 > 17) = true, do swap → [17, 55, 22, 38, 13, 90]
set Sorted = false
index++ = 1
Inner Loop Condition: (Index < Size - Pass) = (1 < 6 - 1) = (1 < 5) = true
Enter Inner Loop
If Condition for Swapping: (index 1 > index 2) = (55 > 22) = true, do swap → [17, 22, 55, 38, 13, 90]
set Sorted = false
index++ = 2
Inner Loop Condition: (Index < Size - Pass) = (2 < 6 - 1) = (2 < 5) = true
Enter Inner Loop
If Condition for Swapping: (index 2 > index 3) = (55 > 38) = true, do swap → [17, 22, 38, 55, 13, 90]
set Sorted = false
index++ = 3
Inner Loop Condition: (Index < Size - Pass) = (3 < 6 - 1) = (3 < 5) = true
Enter Inner Loop
If Condition for Swapping: (index 3 > index 4) = (55 > 13) = true, do swap → [17, 22, 38, 13, 55, 90]
set Sorted = false
index++ = 4
Inner Loop Condition: (Index < Size - Pass) = (4 < 6 - 1) = (4 < 5) = true
Enter Inner Loop
If Condition for Swapping: (index 4 > index 5) = (55 > 90) = false, NO swap → [17, 22, 38, 13, 55, 90]
index++ = 5
Inner Loop Condition: (Index < Size - Pass) = (5 < 6 - 1) = (5 < 5) = false
Exit Inner Loop, Back to Outer Loop
End of pass 1 list: [17, 22, 38, 13, 55, 90]

═══════════════════════════════════════════════════════════════════════════════════════════════════

pass++ = 2
set Sorted = false
Outer Loop Condition 1: (Pass < Size) = (2 < 6) = true
Outer Loop Condition 2: (!Sorted) = (!False) = true
Enter Outer Loop because both conditions are true
set Sorted = true
set Index = 0
Inner Loop Condition: (Index < Size - Pass) = (0 < 6 - 2) = (0 < 4) = true
Enter Inner Loop
If Condition for Swapping: (index 0 > index 1) = (17 > 22) = false, NO swap → [17, 22, 38, 13, 55, 90]
index++ = 1
Inner Loop Condition: (Index < Size - Pass) = (1 < 6 - 2) = (1 < 4) = true
Enter Inner Loop
If Condition for Swapping: (index 1 > index 2) = (22 > 38) = false, NO swap → [17, 22, 38, 13, 55, 90]
index++ = 2
Inner Loop Condition: (Index < Size - Pass) = (2 < 6 - 2) = (2 < 4) = true
Enter Inner Loop
If Condition for Swapping: (index 2 > index 3) = (38 > 13) = true, do swap → [17, 22, 13, 38, 55, 90]
set Sorted = false
index ++ = 3
Inner Loop Condition: (Index < Size - Pass) = (3 < 6 - 2) = (3 < 4) = true
Enter Inner Loop
If Condition for Swapping: (index 3 > index 4) = (38 > 55) = false, NO swap → [17, 22, 13, 38, 55, 90]
index++ = 4
Inner Loop Condition: (Index < Size - Pass) = (4 < 6 - 2) = (4 < 4) = false
Exit Inner Loop, Back to Outer Loop
End of pass 2 list: [17, 22, 13, 38, 55, 90]

═══════════════════════════════════════════════════════════════════════════════════════════════════

pass++ = 3
set Sorted = false
Outer Loop Condition 1: (Pass < Size) = (3 < 6) = true
Outer Loop Condition 2: (!Sorted) = (!False) = true
Enter Outer Loop because both conditions are true
set Sorted = true
set Index = 0
Inner Loop Condition: (Index < Size - Pass) = (0 < 6 - 3) = (0 < 3) = true
Enter Inner Loop
If Condition for Swapping: (index 0 > index 1) = (17 > 22) = false, NO swap → [17, 22, 13, 38, 55, 90]
index++ = 1
Inner Loop Condition: (Index < Size - Pass) = (1 < 6 - 3) = (1 < 3) = true
Enter Inner Loop
If Condition for Swapping: (index 1 > index 2) = (22 > 13) = true, do swap → [17, 13, 22, 38, 55, 90]
set Sorted = false
index++ = 2
Inner Loop Condition: (Index < Size - Pass) = (2 < 6 - 3) = (2 < 3) = true
Enter Inner Loop
If Condition for Swapping: (index 2 > index 3) = (22 > 38) = false, NO swap → [17, 13, 22, 38, 55, 90]
index++ = 3
Inner Loop Condition: (Index < Size - Pass) = (3 < 6 - 3) = (3 < 3) = false
Exit Inner Loop, Back to Outer Loop
End of pass 3 list: [17, 13, 22, 38, 55, 90]

═══════════════════════════════════════════════════════════════════════════════════════════════════

pass++ = 4
set Sorted = false
Outer Loop Condition 1: (Pass < Size) = (4 < 6) = true
Outer Loop Condition 2: (!Sorted) = (!False) = true
Enter Outer Loop because both conditions are true
set Sorted = true
set Index = 0
Inner Loop Condition: (Index < Size - Pass) = (0 < 6 - 4) = (0 < 2) = true
Enter Inner Loop
If Condition for Swapping: (index 0 > index 1) = (17 > 13) = true, do swap → [13, 17, 22, 38, 55, 90]
set Sorted = false
index++ = 1
Inner Loop Condition: (Index < Size - Pass) = (1 < 6 - 4) = (1 < 2) = true
Enter Inner Loop
If Condition for Swapping: (index 1 > index 2) = (17 > 22) = false, NO swap → [13, 17, 22, 38, 55, 90]
index++ = 2
Inner Loop Condition: (Index < Size - Pass) = (2 < 6 - 4) = (2 < 2) = false
Exit Inner Loop, Back to Outer Loop
End of pass 4 list: [13, 17, 22, 38, 55, 90]

═══════════════════════════════════════════════════════════════════════════════════════════════════

pass++ = 5
set Sorted = false
Outer Loop Condition 1: (Pass < Size) = (5 < 6) = true
Outer Loop Condition 2: (!Sorted) = (!False) = true
Enter Outer Loop because both conditions are true
set Sorted = true
set Index = 0
Inner Loop Condition: (Index < Size - Pass) = (0 < 6 - 5) = (0 < 1) = true
Enter Inner Loop
If Condition for Swapping: (index 0 > index 1) = (13 > 17) = false, NO swap → [13, 17, 22, 38, 55, 90]
index++ = 1
Inner Loop Condition: (Index < Size - Pass) = (1 < 6 - 5) = (1 < 1) = false
Exit Inner Loop, Back to Outer Loop
End of pass 5 list: [13, 17, 22, 38, 55, 90]

═══════════════════════════════════════════════════════════════════════════════════════════════════

pass++ = 6
set Sorted = false
Outer Loop Condition 1: (Pass < Size) = (6 < 6) = false
Outer Loop Condition 2: (!Sorted) = (!False) = true
Leave Outer Loop because one of the conditions is not satisfied

═══════════════════════════════════════════════════════════════════════════════════════════════════

Observation: the "improved" bubble sort wasn't utilized in this example because we didn't pass by a whole inner
loop that was completely without swaps (so that sorted remains true) and therefore stopping the outer loop 
before all passes are made. It makes sense that improved bubble sort didn't get utilized here because this is 
an average case scenario where some comparisons had swaps while others didn't so the improved bubble sort isn't
guaranteed to work, and in this case, it didn't. This basically means that we would get the same tracing with 
same number of comparisons even with the regular bubble sort.

Total comparisons: 15 (makes sense because 6(6-1)/2 = 15)
Total swaps: 7 (further proof that this is the average case scenario, because worst is swaps = comparisons)

═══════════════════════════════════════════════════════════════════════════════════════════════════
═══════════════════════════════════════════════════════════════════════════════════════════════════

Condensed View:
List: [55, 17, 22, 38, 13, 90]

Pass 1
Comparison: (55 & 17) = swap → [17, 55, 22, 38, 13, 90]
Comparison: (55 & 22) = swap → [17, 22, 55, 38, 13, 90]
Comparison: (55 & 38) = swap → [17, 22, 38, 55, 13, 90]
Comparison: (55 & 13) = swap → [17, 22, 38, 13, 55, 90] // final form of pass 1
Comparison: (55 & 90) = no swap
90 won't be considered in future comparisons

Pass 2
Comparison: (17 & 22) = no swap
Comparison: (22 & 38) = no swap
Comparison: (38 & 13) = swap → [17, 22, 13, 38, 55, 90] // final form of pass 2
Comparison: (38 & 55) = no swap
90 and 55 won't be considered in future comparisons

Pass 3
Comparison: (17 & 22) = no swap
Comparison: (22 & 13) = swap → [17, 13, 22, 38, 55, 90] // final form of pass 3
Comparison: (22 & 38) = no swap
90 and 55 and 38 won't be considered in future comparisons

Pass 4
Comparison: (17 & 13) = swap  → [13, 17, 22, 38, 55, 90] // final form of pass 4
Comparison: (17 & 22) = no swap
90 and 55 and 38 and 22 won't be considered in future comparisons

Pass 5
Comparison: (13 & 17) = no swap
Same final form as pass 4
90 and 55 and 38 and 22 and 17 won't be considered in future comparisons
Only one element is left (13) nothing to compare it against, so this is the last pass
*/
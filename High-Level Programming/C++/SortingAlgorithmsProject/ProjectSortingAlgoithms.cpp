// Instructions to run the code successfully:
// As this code makes use of 4 data files, they must be imported and opened successfully. In order to do that, go to each file,
// right click and choose "Copy as Path" then paste the path in the line of code that opens the file. Then, change all the 
// backslashes to forward slashes.

// Importing necessary headers and libraries
# include <iostream> // library to read input and print output from the user using functions like cin and cout
# include <fstream> // library to read from and write on files using functions like open(), close (), is_open(), eof()
# include <stdlib.h> // header file needed in our program to use the clear console function
# include <ctime> // library in which the clock() function is defined 

using namespace std;

// Globally declared variables
const int SIZE = 100000; // will be used in the loops because all the input files contain 100k elements
// Note that the word size must be in all caps otherwise the compiler throws a runtime error that all the functions' reference to size is ambiguous
int List [100000]; // the array that will store the values of the files
// NOTE that we can't pass an int variable name (such as SIZE) as the size of the array because SIZE is a variable and the size of an array doesn't change after its declaration.
// Even though SIZE is const, const in C++ means read-only but it's still a variable after all
const int RUN = 32000; // Initialising the RUN to get chunks - Usually, the RUN chunk varies from 32 to 64 depending on the size of the array. The merge function will only merge if the subarray chunk has the size of powers of 2.
// Since our array contains 100k elements, then using a RUN size of 32 or 64 would be very unsuitable and it will result in countless recursive calls which will take up all the memory and cause a stack overflow error
// So as 32 is used for an array of about 100 elements, then 100k elements should used a run of 32k 
int CurrentIndex = 0; // variable used to fill the array with the values of the files index by index
int filetype, sortingtype, sortingorder; // input variables of the 3 questions
int sortingtypeconfirm, sortingorderconfirm; // variables used for error catching and validating user input before calling the sorting algorithms
ifstream InputFile; // ifstream is a predefined fstream class to read from files - InputFile is the object name
ofstream OutputFile; // ofstream is a predefined fstream class to write on file - OutputFile is the object name

// Globally declared functions
// This program contains a total of 20 functions (counting main) with the following prototypes

// 3 Unoptimized sorting algorithms
void BubbleSort (int List [], char sortingorder); // lecture code
void SelectionSort (int List [], char sortingorder); // lecture code
void InsertionSort (int List [], char sortingorder); // lecture code

// 3 Optimized sorting algorithms
void BubbleSortV2 (int List [], char sortingorder); // lecture code - (early termination) stops after a whole pass finishes without swaps
void SelectionSortV2 (int List [], char sortingorder); // finds the minimum and maximum in each pass (so it sorts 2 elements per pass)
void InsertionSortV2 (int List [], char sortingorder); // Tim Sort

// InsertionSortV2 associated/helper functions
void InsertSort (int arr[], int left, int right, char sortingorder);
void Merge (int arr[], int l, int m, int r, char sortingorder);

// Functions to read and write external .txt files
void ReadFile (int filetype); // to open and read any of the provided 3 files that will be sorted
void CheckRead (); // to check of the file is opened successfully and if so, copy the data in the file into out List [100000] array
void WriteFile (int List []); // to print the output of the now sorted array on an output file to avoid cluttering the terminal with output

void CourseBanner (); // prints the course name using ASCII art
void Timer (clock_t StartTime, clock_t EndTime); // calculates and displays the processor time consumed during the sorting only (not the whole program)
void Question1ChooseInputFileType();
void Question2ChooseSortingAlgorithm ();
void Question2Confirm (); // to catch invalid input and avoid errors
void Question3ChooseSortingOrder();
void Question3Confirm(); // to catch invalid input and avoid errors
void CallSortingAlgorithm (int sortingtypeconfirm, int sortingorderconfirm); // finally calling the appropriate sorting algorithm

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

int main () // function defintion
{
    // A concise function body mainly consisting of function calls

    system("cls"); // function call - used to clear the console from all previous output - system() is a function of stdlib.h header file
    CourseBanner (); // function call

    Question1ChooseInputFileType(); // function call
    Question2ChooseSortingAlgorithm (); // function call
    Question3ChooseSortingOrder(); // function call

    CallSortingAlgorithm (sortingtypeconfirm, sortingorderconfirm); // function call

    cout << "The sorting result is ready in the output file!" << endl;

    OutputFile.close(); 
    // note: the files automatically close when the program finishes executing, but it's proper and formal syntax to close them manually after they're no longer needed
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void CourseBanner () // function defintion
{
    // The purpose of this function is terminal interface design so that the program may be user friendly and to make up for the lack of GUI

    cout << R"(   
    ____     ___   ______    ___           _____  ______    ____    __  __   ______  ______   __  __    ____     ______   _____
   / __ \   /   | /_  __/   /   |         / ___/ /_  __/   / __ \  / / / /  / ____/ /_  __/  / / / /   / __ \   / ____/  / ___/
  / / / /  / /| |  / /     / /| |         \__ \   / /     / /_/ / / / / /  / /       / /    / / / /   / /_/ /  / __/     \__ \ 
 / /_/ /  / ___ | / /     / ___ |        ___/ /  / /     / _, _/ / /_/ /  / /___    / /    / /_/ /   / _, _/  / /___    ___/ / 
/_____/  /_/_ |_|/_/  ___/_/  |_|     __/____/__/_/ ____/_/ |_|__\____/___\____/___/_/_____\____/  _/_/ |_|  /_____/___/____/  
   /   |   / | / /   / __ \          /   |   / /   / ____/  / __ \   / __ \   /  _/ /_  __/   / / / /   /  |/  /  / ___/       
  / /| |  /  |/ /   / / / /         / /| |  / /   / / __   / / / /  / /_/ /   / /    / /     / /_/ /   / /|_/ /   \__\        
 / ___ | / /|  /   / /_/ /         / ___ | / /___/ /_/ /  / /_/ /  / _, _/  _/ /    / /     / __  /   / /  / /   ___/ /        
/_/  |_|/_/ |_/   /_____/         /_/  |_|/_____/\____/   \____/  /_/ |_|  /___/   /_/     /_/ /_/   /_/  /_/   /____/      
    )" << endl;

    // The problem with printing ASCII art was that the escape sequences \ are interpreted as single special or other characters
    // which causes errors to occur, so to fix it the raw string literal R"()" have been used. 
    // It is a string in which the escape characters like ‘ \n, \t, or \” ‘ of C++ are not processed so they get printed as they are.
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Question1ChooseInputFileType() // function defintion
{
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Pick the number of the file type that you want to sort." << endl << endl; // Question 1
    cout << "1. Sorted Ascending\n2. Sorted Descending\n3. Unsorted" << endl << endl; // Displaying options
    cout << "> "; // pointer where (and when) the user should type input
    cin >> filetype;
    ReadFile (filetype); // function call
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Question2ChooseSortingAlgorithm () // function defintion
{
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Pick the number of the sorting algorithm that you'd like to use." << endl <<  endl; // Question 2
    cout << "1. Bubble Sort V1\t \t2. Bubble Sort V2" << endl; // Displaying options
    cout << "3. Selection Sort V1\t \t4. Selection Sort V2" << endl; // Displaying options
    cout << "5. Insertion Sort V1\t \t6. Insertion Sort V2" << endl << endl; // Displaying options
    cout << "> ";
    cin >> sortingtype;

    Question2Confirm (); // function call to validate the user input or ask them to reenter
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Question2Confirm () // function defintion
{
    // implementing error (invalid input) catching

    if (sortingtype == 1 || sortingtype == 2 || sortingtype == 3 || sortingtype == 4 || sortingtype == 5 || sortingtype == 6)
        sortingtypeconfirm = sortingtype;

    else
    {
            // To catch any input (integer - character - special character) that is other than 1, 2, 3, 4, 5, 6
            cout <<"Invalid input!" << endl;
            cin.clear(); // helps in clearing the error flags which are set when cin >> fails to interpret the input
            // because the type of the user input is different than the type set for the variable
            cin.ignore(); // helps in removing the input contents that have caused the read failure
            cout << "Please enter a number between 1 and 6." << endl;
            cin >> sortingtype; // taking the input again
            Question2Confirm(); // evaluating the input again
    }

}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Question3ChooseSortingOrder() // function defintion
{
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Pick the number of the sorting order." << endl << endl; // Question 3
    cout << "1. Ascending\n2. Descending" << endl << endl; // Displaying options
    cout << "> ";
    cin >> sortingorder;

    Question3Confirm(); // function call
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Question3Confirm() // function defintion
{
    if (sortingorder == 1 || sortingorder == 2)
        sortingorderconfirm = sortingorder;

    else
    {
        cout <<"Invalid input!" << endl;
        cin.clear(); // helps in clearing the error flags which are set when cin >> fails to interpret the input
        // because the type of the user input is different than the type set for the variable
        cin.ignore(); // helps in removing the input contents that have caused the read failure
        cout << "Please enter a number between 1 and 2." << endl;
        cin >> sortingorder; // taking the input again
        Question3Confirm(); // evaluating the input again
    }

}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void ReadFile (int filetype) // function defintion
{
    // There are 3 possible files to read (sorted ascendingly, sorted descendingly, and unsorted)

    switch(filetype)
    {
        case 1:
            InputFile.open("C:/VS Code/C++ (Advanced)/InputListSortedAscending.txt"); // the directory of the ascending file
            CheckRead (); // function call
            break; // without break case 2 would execute and if there is no break in case 2 either then case 3 would execute and so on

        case 2:
            InputFile.open("C:/VS Code/C++ (Advanced)/InputListSortedDescending.txt"); // the directory of the descending file  
            CheckRead (); // function call
            break;

        case 3:
            InputFile.open("C:/VS Code/C++ (Advanced)/InputListUnsorted.txt"); // the directory of the random file
            CheckRead (); // function call
            break;

        default:
            // To catch any input (integer - character - special character) that is other than 1, 2, 3
            cout<<"Invalid input!" << endl;
            cin.clear(); // helps in clearing the error flags which are set when cin >> fails to interpret the input
            // because the type of the user input is different than the type set for the variable
            cin.ignore(); // helps in removing the input contents that have caused the read failure
            cout << "Please enter a number between 1 and 3." << endl;
            cin >> filetype; // taking the input again
            ReadFile (filetype); // evaluating the input again
            break; 

            // Note that using if (filetype >= 'A' && filetype <= 'Z') is unsuccessful in catching character-type input 
            // and causes the program to loop many times when the user enters a character while the compiler is expecting 
            // an integer because filetype >= 'A' is an illogical condition to the compiler as it regards it as something
            // that couldn't possibly happen since it's aware that filetype is of type integer, so why would it involve
            // it using relational operators with characters
    }

    
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void CheckRead () // function definition
{
    if (InputFile.is_open()) // pre-defined function to check if the file opened successfully
	{ 
        while (true) // loop that runs forever since the value of true doesn't change
        // this means this loop must be broken from the inside because there is no other place to stop it
        { 
            int x; 
            InputFile >> x; // the input file is what provides us with the values of x, unlike what we're used to with the user being the one to give input

            List[CurrentIndex++] = x; // assigning the numbers in the file to the List array one by one

            if (InputFile.eof()) // function to check if we reached the end of the file
            // eof () is a predefined function in the <fstream> library that returns a boolean value
            // it returns true if the file has no more data
            // it returns false if the file still has data
            {
                break; // stopping the loop because the file is finished and there is no more input to fill the array with
            } 
        } 

            // Now that we have taken all the numbers from the file and assigned them to indexes in the List array, 
            // we don't need the file anymore and can close it

            InputFile.close(); // the close () function doesn't take arguments
    }

    else
    {
        cout << "Unable to open the file." << endl;
    }

}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void CallSortingAlgorithm (int sortingtypeconfirm, int sortingorderconfirm) // function defintion
{
    switch(sortingtypeconfirm)
    {
        case 1:
            if (sortingorderconfirm == 1)
                BubbleSort (List, 'A'); // function call in ascending order
            else if (sortingorderconfirm == 2)
                BubbleSort (List, 'D'); // function call in descending order
            break;

        case 2:
            if (sortingorderconfirm == 1)
                BubbleSortV2 (List, 'A'); // function call in ascending order
            else if (sortingorderconfirm == 2)
                BubbleSortV2 (List, 'D'); // function call in descending order
            break;

        case 3:
            if (sortingorderconfirm == 1)
                SelectionSort (List, 'A'); // function call in ascending order
            else if (sortingorderconfirm == 2)
                SelectionSort (List, 'D'); // function call in descending order
            break;

        case 4:
            if (sortingorderconfirm == 1)
                SelectionSortV2 (List, 'A'); // function call in ascending order
            else if (sortingorderconfirm == 2)
                SelectionSortV2 (List, 'D'); // function call in descending order
            break;

        case 5:
            if (sortingorderconfirm == 1)
                InsertionSort (List, 'A'); // function call in ascending order
            else if (sortingorderconfirm == 2)
                InsertionSort (List, 'D'); // function call in descending order
            break;

        case 6:
            if (sortingorderconfirm == 1)
                InsertionSortV2 (List, 'A'); // function call in ascending order
            else if (sortingorderconfirm == 2)
                InsertionSortV2 (List, 'D'); // function call in descending order
            break;

        // No need for a default case as we already implemented the error catching using our own functions

    }
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void BubbleSort (int List [], char sortingorder) // function defintion
{
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Sorting in progress ... " << endl; 
    // a message to display to the user while they wait indefinitely till the sorting is finished so that they're aware of what's happening

    if (sortingorder == 'A') // sorting ascendingly
    {
        clock_t StartTime = clock (); // This line records the time right before the code enclosed between StartTime and EndTime runs
        // clock_t is a clock type capable of representing clock tick counts.
        // Clock ticks are units of time of a constant but system-specific length
        // clock () returns the approximate processor time that is consumed by the program expressed in clock ticks
        // The clock() time depends on how the operating system allocate resources to the process that’s why clock() time may be slower or faster than the actual clock.

        int pass, tempValue;

        for (pass = 1; pass < SIZE; pass++) // is used to control the number of passes needed and to make sure that there are still elements in the array to sort
        {
            for (int index = 0; index < SIZE - pass; index++) 
            // using (size - pass) in the control parameter because at the end of each pass the number of elements that are sorted is 
            // the same as the number of the pass (i.e. pass 1 ends with 1 element sorted and pass 2 ends with 2 elements sorted etc..)

            {

                if (List [index] > List [index + 1]) // to compare the adjacent elements, sort in ascending order - moves the largest elements to the end of the array
                {
                    // swapping process
                    tempValue = List [index];
                    List [index] = List [index + 1];
                    List [index + 1] = tempValue;
                }

            }

        }

        clock_t EndTime = clock (); // This line records the time right after the code enclosed between StartTime and EndTime finishes running
        Timer (StartTime, EndTime); // function call
        WriteFile(List); // function call

    }

    else if (sortingorder == 'D') // sorting descendingly
    {
        // No need to comment as the bubble sort process is already explained above
        // Will only bring attention to the line that has a different condition from the ascending order code 

        clock_t StartTime = clock ();
        int pass, tempValue;

        for (pass = 1; pass < SIZE; pass++)
        {
            for (int index = 0; index < SIZE - pass; index++) 
            {

                if (List [index] < List [index + 1]) // changed > to < to sort in descending
                {
                    tempValue = List [index];
                    List [index] = List [index + 1];
                    List [index + 1] = tempValue;
                }

            }

        }

        clock_t EndTime = clock ();
        Timer (StartTime, EndTime);
        WriteFile(List);
    }

    
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void BubbleSortV2 (int List [], char sortingorder) // function defintion
{
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Sorting in progress ... " << endl;

    if (sortingorder == 'A') // sorting ascendingly
    {
        clock_t StartTime = clock ();
        int temp;
        bool sorted = false; 
        // false is the case when swaps occur, so, at the beginning, we assume the list to be unsorted
        // this is the game-changing variable flag, it will be used to signal whether a swap occurred during the pass
        // In the external loop, it is set to true, and if there is a swap, the inner loop will set it to false
        // Another pass will continue if the sorted is false
        // Passes will stop is sorted is true

        for (int pass = 1; (pass < SIZE) && (!sorted); pass++) // outer loop
        {
            sorted = true; // assume sorted

            for (int index = 0; index < SIZE - pass; index++) // inner loop
            {
                if (List [index] > List [index + 1]) 
                // if the element on the left is greater than the element on the right then they must be swapped because they must be in ascending order
                {
                    // swapping the adjacent list elements
                    temp = List [index];
                    List [index] = List [index + 1];
                    List [index + 1] = temp;

                    sorted = false; 
                    // to signal that we did a swap and assume that the list may still not be sorted
                }

            }

        }

         clock_t EndTime = clock ();
         Timer (StartTime, EndTime);
         WriteFile(List);
    }

    else if (sortingorder == 'D') // sorting descendingly
    {
        clock_t StartTime = clock ();
        int temp;
        bool sorted = false; 

        for (int pass = 1; (pass < SIZE) && (!sorted); pass++)
        {
            sorted = true;

            for (int index = 0; index < SIZE - pass; index++)
            {
                if (List [index] < List [index + 1]) // changed > to < to sort in descending
                {
                    temp = List [index];
                    List [index] = List [index + 1];
                    List [index + 1] = temp;

                    sorted = false; 
                }

            }

        }

         clock_t EndTime = clock ();
         Timer (StartTime, EndTime);
         WriteFile(List);
    }
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void SelectionSort (int List [], char sortingorder) // function defintion
{
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Sorting in progress ... " << endl;

    if (sortingorder == 'A') // sorting ascendingly
    {
        clock_t StartTime = clock ();

        for (int lastIndex = SIZE-1; lastIndex >= 1; lastIndex--) // outer loop
        {
            int largestNumberIndex = 0; // largest item is assumed to be at the start of the array

            for (int index = 1; index <= lastIndex; index++) // inner loop
            // index starts from 1 because we already assumed that the max is at index 0
            {
                if (List[index] > List[largestNumberIndex]) // compare every element in the array with the max element found thus far
                {
                    largestNumberIndex = index; // now largestIndex becomes the index of the true largest item found
                }
            }
            
            // swap the true max element with the element at the last index in the array because this is ascending sort
            // so at the end of the pass we will have sorted 1 element (the max)
            int temp = List[largestNumberIndex];
            List[largestNumberIndex] = List[lastIndex];
            List[lastIndex] = temp;

        }

        clock_t EndTime = clock ();
        Timer (StartTime, EndTime);
        WriteFile(List);
    }

    else if (sortingorder == 'D') // sorting descendingly
    {
        clock_t StartTime = clock ();

        for (int lastIndex = SIZE-1; lastIndex >= 1; lastIndex--)
        {
            int smallestNumberIndex = 0; // smallest item is assumed to be at the start of the array

            for (int index = 1; index <= lastIndex; index++)
            {
                if (List[index] < List[smallestNumberIndex]) // compare every element in the array with the max element found thus far
                {
                    smallestNumberIndex = index; // now smallestIndex becomes the index of the true smallest item found
                }
            }
            
            // swap the true min element with the element at the last index in the array because this is descending sort
            // so at the end of the pass, we will have sorted 1 element (the min)
            int temp = List[smallestNumberIndex];
            List[smallestNumberIndex] = List[lastIndex];
            List[lastIndex] = temp;

        }

        clock_t EndTime = clock ();
        Timer (StartTime, EndTime);
        WriteFile(List);
    }
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void SelectionSortV2 (int List [], char sortingorder) // function defintion
{
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Sorting in progress ... " << endl;

    if (sortingorder == 'A') // sorting ascendingly
    {   
        clock_t StartTime = clock ();

        for (int lastIndex = SIZE-1, firstIndex = 0; firstIndex < lastIndex; lastIndex--, firstIndex++) // outer loop
        {
            int MaxIndex = firstIndex, MinIndex = firstIndex; // assuming both min and max are at the start of the array
            int Max = List[firstIndex], Min = List[firstIndex];

            for (int index = firstIndex; index <= lastIndex; index++) // inner loop
            {
                if (List[index] > Max) // compare every element in the array with the max element found thus far
                {
                    Max = List[index];
                    MaxIndex = index; // now MaxIndex becomes the index of the true max item found
                }

                else if (List[index] < Min) // compare every element in the array with the min element found thus far
                {
                    Min = List[index];
                    MinIndex = index; // now MinIndex becomes the index of the true min item found
                }
            }
            
            // swap the true max element with the element at the last index in the array because this is ascending sort
            // swap the true min element with the element at the first index in the array because this is ascending sort
            // so at the end of the pass we will have sorted 2 elements (the max and the min)

            swap (List[firstIndex], List[MinIndex]);

            if (List[MinIndex] == Max)
                swap (List[lastIndex], List[MinIndex]);
            
            else
                swap (List[lastIndex], List[MaxIndex]);
        }

        clock_t EndTime = clock ();
        Timer (StartTime, EndTime);
        WriteFile(List);
    }

    else if (sortingorder == 'D') // sorting descendingly
    {
        clock_t StartTime = clock ();

        for (int lastIndex = SIZE-1, firstIndex = 0; firstIndex < lastIndex; lastIndex--, firstIndex++) // outer loop
        {
            int MaxIndex = firstIndex, MinIndex = firstIndex; // assuming both min and max are at the start of the array
            int Max = List[firstIndex], Min = List[firstIndex];

            for (int index = firstIndex; index <= lastIndex; index++) // inner loop
            {
                if (List[index] > Max) // compare every element in the array with the max element found thus far
                {
                    Max = List[index];
                    MaxIndex = index; // now MaxIndex becomes the index of the true max item found
                }

                else if (List[index] < Min) // compare every element in the array with the min element found thus far
                {
                    Min = List[index];
                    MinIndex = index; // now MinIndex becomes the index of the true min item found
                }
            }
            
            // swap the true max element with the element at the first index in the array because this is descending sort
            // swap the true min element with the element at the last index in the array because this is descending sort
            // so at the end of the pass we will have sorted 2 elements (the max and the min)

            swap (List[firstIndex], List[MaxIndex]);

            if (List[MaxIndex] == Min)
                swap (List[lastIndex], List[MaxIndex]);
            
            else
                swap (List[lastIndex], List[MinIndex]);
        }

        clock_t EndTime = clock ();
        Timer (StartTime, EndTime);
        WriteFile(List);
    }
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void InsertionSort (int List [], char sortingorder) // function defintion
{
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Sorting in progress ... " << endl;

    if (sortingorder == 'A') // sorting ascendingly
    {
        clock_t StartTime = clock ();
        int item, pass, insertIndex;

        for (pass = 1; pass < SIZE; pass++) // outer loop to control the passes and that there are still elements left in the array to sort
        {
            item = List [pass]; // first item in the unsorted array
            insertIndex = pass; // index of the first item in the unsorted array

            while ((insertIndex > 0) && (List [insertIndex - 1] > item)) 
            {
                List [insertIndex] = List [insertIndex - 1];
                insertIndex--;
            }

            List [insertIndex] = item; // insert item at the right place

        }

        clock_t EndTime = clock ();
        Timer (StartTime, EndTime);
        WriteFile(List);

    }

    else if (sortingorder == 'D') // sorting descendingly
    {
        clock_t StartTime = clock ();
        int item, pass, insertIndex;

        for (pass = 1; pass < SIZE; pass++)
        {
            item = List [pass];
            insertIndex = pass;

            while ((insertIndex > 0) && (List [insertIndex - 1] < item)) // change > to < to sort in descending order
            {
                List [insertIndex] = List [insertIndex - 1];
                insertIndex--;
            }

            List [insertIndex] = item;

        }

        clock_t EndTime = clock ();
        Timer (StartTime, EndTime);
        WriteFile(List);
    }
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void InsertionSortV2 (int List [], char sortingorder) // function definition
{
    // There are 5 possible ways to improve insertion sort (discussed in the report)
    // Also discussed in the report is the reason why we chose Tim Sort as our improvement
    
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Sorting in progress ... " << endl;

       clock_t StartTime = clock ();

        for (int i = 0; i < SIZE; i = i + RUN) 
        {
            InsertSort (List, i, min((i+RUN-1), (SIZE-1)), sortingorder); // function call
        }

        for (int s = RUN; s < SIZE; s = 2*s) // Start merging from size RUN (or 32). It will continue upto 2*RUN
        // This line initiates a loop that doubles the size of the chunks that are being merged. The loop continues until the size of 
        // the chunks reaches the size of the array.
        {
            // pick starting point of left sub array. We are going to merge arr[left..left+size-1] and arr[left+size, left+2*size-1]
            // After every merge, we increase left by 2*size

            for (int left = 0; left < SIZE; left += 2*s) 
            //  This line initiates a loop that iterates through the array in chunks of size 2*s. This is where the merging of the chunks occurs.
            {
                int mid = left + s - 1; // find ending point of left sub array mid+1 is starting point of right sub array
                int right = min((left + 2*s - 1), (SIZE-1));
                // The min function is used to ensure that the right end point does not go beyond the size of the array.
                Merge(List, left, mid, right, sortingorder); // function call to merge sub array arr[left.....mid] & arr[mid+1....right]
            }
        
        }

       clock_t EndTime = clock ();
       Timer (StartTime, EndTime);
       WriteFile(List);
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void InsertSort (int arr[], int left, int right, char sortingorder) // Implementing insertion sort for RUN size chunks
{
    if (sortingorder == 'A')
    {
        for (int i = left + 1; i <= right; i++)
        {
            int j = i - 1;
            int t = arr[i]; // The current element arr[i] is assigned to a temporary variable t

            while (j >= left && arr[j] > t)
            {
                arr[j+1] = arr[j];
                j--;
            }

            arr[j+1] = t;

        }
    }

    else if (sortingorder == 'D')
    {
        for (int i = left + 1; i <= right; i++)
        {
            int j = i - 1;
            int t = arr[i]; // The current element arr[i] is assigned to a temporary variable t

            while (j >= left && arr[j] < t) // this is the change of operator that makes it sort descendingly
            {
                arr[j+1] = arr[j];
                j--;
            }

            arr[j+1] = t;

        }
    }

}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/
        
void Merge (int arr[], int l, int m, int r, char sortingorder) // using the merge function the sorted chunks of size 32 are merged into one
{
    if (sortingorder == 'A') // sorting ascendingly
    {
        
        int len1 = m - l + 1, len2 = r - m; // calculating the lengths of the left and right sub-arrays.
        int* left = new int [len1];
        int* right = new int [len2];

        for (int i = 0; i < len1; i++) // iterating through the left sub-array and copying its elements into the left array.
        {
            left[i] = arr[l + i]; // Filling left array
        }
                
        for (int i = 0; i < len2; i++) // iterating through the right sub-array and copying its elements into the right array.
        {
            right[i] = arr[m + 1 + i]; // Filling right array
        }

        int i = 0;
        int j = 0;
        int k = l;

        // We are merging the left and right sub-arrays into a single sorted array. We iterate through the left and right arrays using the 
        // indices i and j respectively. We compare the values at the ith and jth positions in the left and right arrays respectively, and 
        // copy the smaller value into the arr array at position k. We then increment i, j, and k accordingly.

        while (i < len1 && j < len2) // Iterate into both arrays left and right
        {
            if (left[i] <= right[j]) // IF element in left is less then increment i by pushing into larger array
            {
                arr[k] = left[i];
                i++;
            } 

            else 
            {
                arr[k] = right[j]; // Element in right array is greater increment j
                j++;
            }
            
            k++;
        }

        while (i < len1) // This loop copies remaining element in left array
        {
            arr[k] = left[i];
            k++;
            i++;
        }

        while (j < len2) // This loop copies remaining element in right array
        {
            arr[k] = right[j];
            k++;
            j++;
        }

        delete[] left;
        delete[] right;
    }

    else if (sortingorder == 'D') // sorting descendingly
    {
        int len1 = m - l + 1, len2 = r - m; 
        int* left = new int [len1];
        int* right = new int [len2];

        for (int i = 0; i < len1; i++)
        {
            left[i] = arr[l + i];
        }
                
        for (int i = 0; i < len2; i++) 
        {
            right[i] = arr[m + 1 + i]; 
        }

        int i = 0;
        int j = 0;
        int k = l;

        while (i < len1 && j < len2) 
        {
            if (left[i] >= right[j]) // change this condition to change the sorting order to descending
            {
                arr[k] = left[i];
                i++;
            } 

            else 
            {
                arr[k] = right[j]; 
                j++;
            }
                k++;
        }

        while (i < len1) 
        {
            arr[k] = left[i];
            k++;
            i++;
        }

        while (j < len2) 
        {
            arr[k] = right[j];
            k++;
            j++;
        }

        delete[] left;
        delete[] right;
    }

}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void WriteFile (int List []) // function defintion
{
    // As we're not allowed to modify the original input files, we've resorted to creating an output file to display the results 
    // of the sorting instead of cluttering the output console with unreadable numbers
    
    OutputFile.open("C:/VS Code/C++ (Advanced)/OutputListSorted.txt"); // opening the output file using its directory in the memory

    for (int index = 0; index < SIZE; index++) // printing the sorted array onto the output file
    {
        OutputFile << List [index]; // instead of using cout << to print on the terminal, we print on the output file using OutputFile <<

        if (index != SIZE-1) // to avoid having an extra empty new line after printing 100,000 numbers
        {
            OutputFile << endl;
        }
    }

}

/* ══════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Timer (clock_t StartTime, clock_t EndTime)
{
    cout << "Processor time taken for sorting is " << double ((EndTime - StartTime))/CLOCKS_PER_SEC << " seconds." << endl;
    // The difference between the time the code starts running and the time it finishes is the total time, and divided over how many ticks
    // there are per second, it gives the amount of time the code took to run in seconds.
}
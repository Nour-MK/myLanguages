// Consider the following function definition, Which of the options is an incorrect
 function call?

void too2 (int myArray[], int howMany)
{
for (int index=0; index<howMany; index++)
a[index]=2;
}

// The options :

1. int myArray[29];
too2 (myArray, 55);
// Because 55 is out of range. In calling a function and giving parameter that is an array we write its name
// in the first digit and its size in the second digit. 55 isn't an acceptable size as the max size myArray can be is 29

2. int myArray[29];
too2 (myArray, 29);

3. int myArray [29];
too2(myArray, 10);

4. int myArray [29];
too2(myArray, 22);
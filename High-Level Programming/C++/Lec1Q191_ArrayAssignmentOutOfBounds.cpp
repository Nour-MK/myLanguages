// What is wrong with the following piece of code?

int sampleArray[10];
for (int index = 1; index <= 10; index++)
sampleArray[index] = 3*index;

// it tries to assign a value to an index which is out of range for the array
// as there is no element sin array sampleArray with the index [10], the max index 
// in sampleArray is 9
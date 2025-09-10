// Consider the following function defintion and circle which of the options is an
 incorrect function call

void tripler (int &n)
{
n=3*n;
}

// The options :

1. int a[3]= {4,5,6}, number=2;
tripler (a[2]);

2. int a[3]= {4,5,6}, number=2;
tripler (a[3]);
// This one is an incorrect function call because don't get confused with the array size and the max index
// There is no element in array a with the index 3 to triple it using the function we're calling

3. int a[3]= {4,5,6}, number=2;
tripler (a[number]);

4. int a[3]= {4,5,6}, number=2;
tripler (number);
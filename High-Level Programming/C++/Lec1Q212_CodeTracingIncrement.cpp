/* No programming interview would be complete without performing a code tracing exercise.
The int is one of the basic data types that can be manipulated by using the unary ++ operator. */
int main()
{
int a, b, c;        // int data type for simple math
a = 9;
c = a + 1 + 1 * 0;
b = c++;
 
return 0;           // return main int as Exit Status 0 (success)
} 

// a = 9 (was not modified)
// b = 10
// c = 11
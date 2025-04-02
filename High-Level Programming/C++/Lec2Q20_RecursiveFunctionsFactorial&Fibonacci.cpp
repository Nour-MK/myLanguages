/*
Question: Write a C++ program with two recursive functions (Factorial and fibonacci). 
Call them (both) from the main function. 
So, if the user inserts N, the program will find both N! and Fib(N).  
*/

# include <iostream> // header
using namespace std;

/* ═════════════════════════════════════════════════════════════════════════════════════*/

int factorial (int F) // function
{
    if (F == 0 || F == 1) // terminal case (must be reached at some point)
    return 1;

    else // general case
    return F * factorial(F-1); // recursive call
}

// 0! = 1
// 1! = 1 x 0! = 1 x 1 = 1
// 2! = 2 x 1! = 2 x 1 x 1 = 2
// 3! = 3 x 2! = 3 x 2 x 1 x 1 = 6
// 4! = 4 x 3! = 4 x 3 x 2 x 1 x 1 = 24

// Implementation using an increasing loop
/*
int main ()
{
    int fact = 1;
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        fact = fact*1;
    }
    cout << fact;
}
*/

// Implementation using a decreasing loop
/*
int main ()
{
    int fact = 1;
    int n = 4;
    for (int i = n; i >= 1; i--)
    {
        fact = fact * 1;
    }
    cout << fact;
}
*/

/* ═════════════════════════════════════════════════════════════════════════════════════*/

int fibonacci (int F) // function
{
    if (F <= 0) // terminal case 1
    return 0;

    else if (F == 1) // terminal case 2
    return 1;

    else // general case
    return fibonacci (F-1) + fibonacci (F-2); // recursive calls
    // fibonacci (F-1) will finish executing completely first then fibonacci (F-2) will have its turn
    // So, no, they're not called at the same time.
}

// Every fibonacci series is the result of adding 2 previous fibonacci numbers.
// Fibonacci series starts with 0 and 1
// Fibonacci series: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
// NOTE THAT we start counting the entries of the series from 0, so the 4th fib number is 3

// Implementation using a loop that prints the first 10 fibonacci numbers
/*
int main ()
{
    int t1 = 0, t2 = 1, result;

    for (int i = 1; i < 11; i++)
    {
        cout << result << " ";
        result = t1 + t2;
        t1 = t2;
        t2 = result;
    }
}
*/

// Implementation using a loop that prints the fibonacci number of a 
/*
int main ()
{
    int t1 = 0, t2 = 1, result, number;
    cout << "What number would you like to find the fibonacci number of? ";
    cin >> number;

    for (int i = 1; i<number; i++)
    {
        result = t1 + t2;
        t1 = t2;
        t2 = result;
    }

    cout << "The Fibonacci number for " << number << " is " << result;
}
*/

/* ═════════════════════════════════════════════════════════════════════════════════════*/

int main () // function
{
    int x;
    cout << "Enter a positive integer: ";
    cin >> x;

    if (x < 0) // Check if the user entered a positive number
    
    // Note: There's no need to check if the value the user entered is an integer
    // because it will be automatically type-casted since they are giving input to int x.
    {
        cout << "Invalid entry!" << endl;
        main (); // recursive call
    }

    else 
    {
        cout << "The factorial of " << x << " is " << factorial (x) << endl; // call by value
        cout << "The fibonacci of " << x << " is " << fibonacci (x) << endl; // call by value
    }
}


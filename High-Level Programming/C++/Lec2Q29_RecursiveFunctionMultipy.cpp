# include <iostream>
using namespace std;

// Multiplication of 2 numbers can be achieved using addition
// Example: (8 x 3) = (8 + 8 + 8) = 24 

/*
// Using the loop way
int Multiply (int M, int N)
{
    int result = 0;

    for (int i = 1; i <= N; i++)
    {
        result += M;
    }

    return result;
}
*/

// Using a recursive function
int Multiply (int M, int N) // problem size is represented by variable N
{
    if (N == 1)
    {
        return M; // because any number times 1 is the number itself
    }

    else 
    {
        return M + Multiply (M, N-1);
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    cout << Multiply (8, 3);
}
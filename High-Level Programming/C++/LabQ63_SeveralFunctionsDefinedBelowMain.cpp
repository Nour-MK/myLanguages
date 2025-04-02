# include <iostream>
using namespace std;

void Even (double n1, double n2);
void Odd (double n1, double n2);
void SumOfEven (double n1, double n2);
void SumOfSquareOfOdd (double n1, double n2);

/* ═════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    double n1, n2;
    cout << "Enter two numbers." << endl;
    cout << "Note: The 1st number must be less than the 2nd number." << endl;
    cin >> n1 >> n2;

    if (n1 < n2)
    {
        Even (n1, n2);
        Odd (n1, n2);
        SumOfEven (n1, n2);
        SumOfSquareOfOdd (n1, n2);
    }

    else
    {
        cout << "Invalid entry. " << n1 << " is greater than " << n2;
    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════*/

void Even (double n1, double n2)
{
    cout << "The even numbers between " << n1 << " and " << n2 << " are ";

    for (int i = n1; i <= n2; i++)
    {
        if (i%2 == 0)
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════*/

void Odd (double n1, double n2)
{
    cout << "The odd numbers between " << n1 << " and " << n2 << " are ";

    for (int i = n1; i <= n2; i++)
    {
        if (i%2 != 0)
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════*/

void SumOfEven (double n1, double n2)
{
    int sum = 0;

    for (int i = n1; i <= n2; i++)
    {
        if (i%2 == 0)
        {
            sum = sum + i;
        }
    }

    cout << "The sum of all the even numbers between " << n1 << " and " << n2 << " = " << sum << endl;

}

/* ═════════════════════════════════════════════════════════════════════════════════════════════*/

void SumOfSquareOfOdd (double n1, double n2)
{
    int sum = 0;

    for (int i = n1; i <= n2; i++)
    {
        if (i%2 != 0)
        {
            sum = sum + (i*i);
        }
    }

    cout << "The sum of the squares of all the odd numbers between " << n1 << " and " << n2 << " = " << sum << endl;

}
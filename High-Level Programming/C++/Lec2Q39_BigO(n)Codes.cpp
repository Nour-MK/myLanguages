// Example 1
for (int i = 1; i <= n; i++)

// Example 2
for (int a = 2; a <= n; a++)

// Example 3
for (int c = 1; c <= n-1; c++)

// Example 4
int n, x, i = 1;
while (i<=n)
{
    x++;
    i++;
}

// Example 5
for	(int x = n;	x >= 0;	x--)

// Example 6
for	(int i = 0;	i <	5n;	i++)	

// Example 7
for (int i = 0; i < n/2; i++)

// Example 8
void foo (int array [])
{
    int sum = 0;
    int product = 1;

    for (int i = 0; i < array.length; i++)
    {
        sum += array [i];
    }
    for (int i = 0; i < array.length; i++)
    {
        product *= array [i];
    }

    cout << sum << " , " << product << endl;
}

// Example 9
int factorial (int n)
{
    if (n < 0)
    {
        return -1;
    }

    else if (n == 0)
    {
        return 1;
    }

    else
    {
        return n * factorial (n - 1);
    }
}

// Example 10
int silly (int n, int m)
{
    if (n < 1)
    {
        return n;
    }

    else if (n < 100)
    {
        return silly (n-m, m); // recursive call
    }

    else
    {
        return silly (n-1, m); // recursive call
    }
}

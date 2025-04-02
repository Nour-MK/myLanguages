// Example 1
for (int i = 0; i <= n*n; i++)

// Example 2
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
}

// Example 3
for (int a = 1; a <= n; a++)
{
    for (int b = 1; b <= a; b++)
}

// Example 4
for (int i = 0; i < n; ++i)
{
    for (int j = n; j > 0; --j)
}

// Example 5
while (i < n)
{
    while (j < n)
}

// Example 6
int a = 0;
for (i = 0; i < N; i++) 
{
    for (j = N; j > i; j--) 
    {
        a = a + i + j;
    }
}

// Example 7
void silly (int n)
{
    j = 0;
    while (j < n) // O(n/5) = O(n)
    {
        for (int i = 0; i < n; i++) // O(n)
        {
            cout << "Something" << endl;
        }
        j = j + 5;
    }
}

// Example 8
void silly (int n)
{
    for (int i = 0; i < n; i = i + 10)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << endl;
            cout << j << endl;
        }
    }
}
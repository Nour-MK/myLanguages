// Example 1
for (int i = x; i <= n; i = i*x) // x must be greater than 1
// for happens log n times because the multiplication causes us to skip numbers
// so it's like we're cutting the number of the input in half
{
    int j = 1;

    while (j <= n) // happens n times
    {
        j++;
    }
}

// Example 2
for (int i = 3; i <= n; i = i * 3)
{
    int j = 1;

    while (j <= n)
    {
        j++;
    }
}

// Example 3
for(int i = 0; i < n; i++) // happens n times
{
    for(int k = 1; k < n; k*=2) // happens log n times
}

// Example 4
for(int k = 2; k < n; k*= k)

// Example 5
for(int i = 0; i < n; i++)
{
    for(int k = n - 1; k > 0; k = k / 3 )
}
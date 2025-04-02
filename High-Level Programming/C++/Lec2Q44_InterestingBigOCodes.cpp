void silly (int n)
{
    for (int i = 0; i < n*n; i++) // O(n^2) times what's nested inside it
    {
        for (int j = 0; j < n; j++) // O(n)
        {
            for (int k = 0; k < i; k++) // O(n) this plus the below

            for (int m = 0; m < 100; m++) // O(1)
        }
    }
}
// O(n^4)

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

for (int i = n; i > 0; i/= 2) // log n
{
    for (int j = 1; j < n; j *= 2) // log n
    {
        for (int k = 0; k < n; k += 2) // O(n/2) = O(n)
    }
}

// (log n * log n * n) = O(n(log(n))^2)

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

for (int i = n; i > 0; i /= 2) // log n
{
    for (int j = 0; j < i; j++) // runs as much times as i runs, so log n too 
}

// since they are nested then (log n * log n) = O((log(n))^2)

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/
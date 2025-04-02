// Example 1
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        for (int k = 1; k <= n; k++)
    }
}

// Example 2
for	(int i = 0;	i <	n; i++)	
{
		for	(int j = 0;	j <	n*n; j++)
}

// Example 3
void silly (int n, int x, int y)
{
    if (x < y)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n * i; j++)
            {
                cout << "Something" << endl;
            }
        }
    }

    else
    {
        cout << "Something else" << endl;
    }
}

// Example 4
void silly (int n, int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        if (x > y)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Something" << endl;
            }

            for (int k = 0; k < n*n; k++)
            {
                cout <<"Another thing" << endl;
            }
        }

        else
        {
            cout << "Something else" << endl;
        }
    }
}

// Example 5
void silly (int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "Hello :)" << endl;

            for (int k = 0; k < j; k++)
            {
                cout << k << endl;
            }
        }
    }
}
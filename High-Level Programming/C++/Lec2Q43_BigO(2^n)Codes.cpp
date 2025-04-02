// Example 1
int i = 1, j = 1;
while (i <= n)
{
    j = j * 2; // doubling
    i++; // increasing by 1
}

for (i = 1; i <= j; i++)
{

}

// Example 2
int fibonacci (int F) // function
{
    if (F <= 0) // terminal case 1
    return 0;

    else if (F == 1) // terminal case 2
    return 1;

    else // general case
    return fibonacci (F-1) + fibonacci (F-2); // 2 recursive calls
}
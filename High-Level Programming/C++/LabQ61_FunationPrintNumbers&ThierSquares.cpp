# include <iostream>
using namespace std;

void squares (int x)
{
    for (int i = 1; i<= x; i++)
    {
        cout << i << " ";
    }

    cout << endl;

    for (int i = 1; i <= x; i++)
    {
        cout << i * i << " ";
    }
}

int main ()
{
    squares (10);
}
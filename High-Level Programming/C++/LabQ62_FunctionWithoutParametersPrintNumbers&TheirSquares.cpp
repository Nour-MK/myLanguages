# include <iostream>
using namespace std;

void squares (void)
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " ";
    }

    cout << endl;

    for (int i = 1; i <= 10; i++)
    {
        cout << i * i << " ";
    }
}

int main ()
{
    squares ();
}
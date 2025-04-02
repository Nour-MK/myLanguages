# include <iostream>
using namespace std;

int main ()
{
    int x, y, z, n, sum;

    cout << "Please type in four numbers" << endl;
    cin >> x >> y >> z >> n;

    sum = x + y + z + n;

    if (sum % 2 == 0)
    {
        cout << "Their sum is " << sum << " and it's even.";
    }

    else
    {
        cout << "Their sum is " << sum << " and it's odd.";
    }
}
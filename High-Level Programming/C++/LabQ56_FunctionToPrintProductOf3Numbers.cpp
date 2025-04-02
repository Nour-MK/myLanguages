# include <iostream>
using namespace std;

void product (double n1, double n2, double n3)
{
    cout << "The product is " << n1 * n2 * n3;
}

/* ══════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    double n1, n2, n3;
    cout << "Enter three numbers you wish to multiply." << endl;
    cin >> n1 >> n2 >> n3;
    product (n1, n2, n3);
}
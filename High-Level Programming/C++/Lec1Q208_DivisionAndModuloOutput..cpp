# include <iostream>
using namespace std;

int main ()
{
    cout << 9/2 << endl;
    // dividing an integer by an integer will result in an integer, so the compiler will take the
    // integer part of the result 4.5 which is 4

    cout << -34%5 << endl;
    // 34/5 = 6.8
    // 6.8 - 6 = 0.8
    // 0.8 * 5 = 4
    // but 4 will be -4 
    // because modulo will assign to it the sign of the first number in the operation
}
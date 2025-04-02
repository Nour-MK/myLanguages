# include <iostream>
using namespace std;

int main ()
{
    cout << !(1 && !(0 || 1));
    
    // you must solve what's between the parenthesis first
    // 0 OR 1 = 1
    // ! 1 = 0
    // 1 AND 0 = 0
    // ! 0 = 1
}
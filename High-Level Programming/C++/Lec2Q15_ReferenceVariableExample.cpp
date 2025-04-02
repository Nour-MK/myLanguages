#include <iostream>
using namespace std;

int main ()
{
    int count;
    int &blah = count; // blah is the same variable as count

    count = 1;
    cout << "blah is " << blah << endl;
    blah ++; // this changes the value in blah which is actually count
    cout << "count is " << count << endl; 
    // this is to prove that the value of count has changed even though we only applied change to blah
}
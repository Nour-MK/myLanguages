#include <iostream>
using namespace std;

bool Palindrome(char arr[], int size)
{
    int start = 0;
    int end = size - 1;
    bool flag;

    while(start < end) 
    {
        if (arr[start] == arr[end])
        flag = true;

        else
        {
            flag = false;
            break;
        }

        start++;
        end--;
    }

    return flag;

}

int main ()
{
    char array[4] = {'A', 'B', 'B', 'A'};

    cout << "The array is ";
    if (Palindrome(array, 4) == true)
    cout << "a palindrome";

    else
    cout<<"not a palindrome";

    return 0;
}
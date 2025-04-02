# include <iostream>
# include <cstring>
using namespace std;

int main ()
{
    char s [200];
    int counter = 0, index = 0;

    cout << "Type a sentence: ";
    cin.getline (s, 200); 
    // standard library function that is used to read a string or a line from an input stream. 
    // it extracts characters from the input stream and appends it to the string object
    // the parameters are the name of the cstring and the size

    do
    {
        if (s[index] == ' ') // counting how many spaces are in the input
        {
            counter++;
        }

        index++;
    } while (s[index] != '\0');

    cout << "There were " << counter << " spaces in your sentence." << endl;
}
# include <iostream>
# include <cstring> // needed to use the strcmp
using namespace std;

class info
// this is the declaration of a class that stores information about the disease and relevant medicine
{
    private:
            char medicine [15]; // cstring
            char disease [15]; // cstring
            // Note how we didn't define a constructor ourselves, so the compiler will generate a
            // default one that does nothing

    public:
            void setMedicine ()
            {
                cout << "Enter the medicine name: ";
                cin >> medicine;
            }

            void setDisease ()
            {
                cout << "Enter the disease name: ";
                cin >> disease;
            }

            char *getMedicine ()
            {
                return medicine;
            }

            char *getDisease ()
            {
                return disease;
            }
};

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void checkMedicine (info x[]) // the size of the argument array doesn't matter but it must be of type class info
// This function requires the user to enter the name of the disease and the function will search
// for the medicine that is suitable for the disease
{
    char disease [20]; // cstring, doesn't require a for loop to write a sentence
    int found = 0;
    
    cout << "Enter the disease name: ";
    cin >> disease;

    for (int index = 0; index < 10; index++)
    {
        if (strcmp (disease, x[index].getDisease()) == 0)
        // Function strcmp takes two strings as arguments and compare these two strings lexicographically. 
        // Meaning that it starts comparison character by character starting from the first character 
        // until the characters in both strings are equal or a NULL character is encountered.
        // If first character in both strings are equal, then this function will check the second character, 
        // if this is also equal then it will check the third and so on
        // This function can return three different integer values based on the comparison:
        // It returns 0 if both strings are found to be identical.
        // It returns a number that is greater than 0 if the first not matching character in 
        // leftStr have the greater ASCII value than the corresponding character in rightStr
        // It returns a number that is less than 0 if the first not matching character in 
        // leftStr have lesser ASCII value than the corresponding character in rightStr.
        {
            cout << "The medicine for " << disease << " is " << x[index].getMedicine ();
            found = 1;
            break; // so that the loop doesn't continue searching after we've found the result
        }
    }

    if (found == 0)
    {
        cout << "Sorry, we cannot find a medicine for your disease.";
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    info data [10]; // this is an array called data of size 10 and type class info

    for (int index = 0; index < 10; index++)
    {
        cout << "Case no. " << index << endl;
        data[index].setMedicine ();
        data[index].setDisease ();
    }

    cout << "Here is a list of disease and their appropriate medication" << endl;
    for (int index = 0; index < 10; index++)
    {
        cout << "Case no. " << index << endl;
        cout << "The medicine is: " << data[index].getMedicine() << endl;
        cout << "The disease is: " << data[index].getDisease() << endl;
    }

    checkMedicine(data); // note how we're passing the whole array data to the function
}
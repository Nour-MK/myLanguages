# include <iostream>
# include <cstring>
using namespace std;

class subject
{
    private:
            char subjectName [20]; // cstring
            char subjectCode [15];
            int subjectCredits;

    public:
            subject (char *, char *, int cre = 3); // constructor with parameters
            // note that if the value of the credits is not passed it will be set to 3 by default
            void getDetail (); // function
            friend void changeSubject (subject &); // friend function prototype inside the class
            // note how the parameter of the function is the class's object


}; // remember the semicolons

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

subject :: subject (char *sub, char *code, int credits) // remember that a constructor has no return type
{
    strcpy (subjectName, sub);
    strcpy (subjectCode, code);
    subjectCredits = credits;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void subject :: getDetail ()
{
    cout << "\nSubject Name: " << subjectName;
    cout << "\nSubject Code: " << subjectCode;
    cout << "\nCredit Hours: " << subjectCredits;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void changeSubject (subject &sub)
// if we wanted to do a constant pass by reference it would look like this
// void changeSubject (const subject &sub)
// but this would generate an error because the function's operations are trying to change the
// data members of sub but the const means it cannot be modified
{
    cout << "\nInsert new subject name: ";
    cin >> sub.subjectName;
    cout << "Insert new subject code: ";
    cin >> sub.subjectCode;
    cout << "Insert new subject credit hours: ";
    cin >> sub.subjectCredits;
    cout << "Get new information for the subject.";
    sub.getDetail(); // print the new values after they have been changed
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    subject DS ("Data Structures C++", "CSCI 215"); // created subject called DS
    DS.getDetail (); // print name as Data Structures, code as CSCI 215 and credits as 3

    changeSubject (DS); // note how we're passing object DS by reference into the function

    cout << "\nView the subject information again: "; // we use this to show that the pass by reference
    // indeed did change the fields of the objects and it reflected outside the function that applied
    // the change, so this change is permanent
    DS.getDetail ();
}
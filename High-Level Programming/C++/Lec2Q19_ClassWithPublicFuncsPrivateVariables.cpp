// The difference between this and the previous example is that the class variables are now private
// This means that even objects of the class have no direct access to the private variables.

// Create objects of class > access class's public member functions > access class's private members

#include <iostream>
using namespace std;

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

class DayOfYear
{
    // Contains data members (variables and functions)

    public:
    void input ();
    void output ();
    void happy_birthday ();

    private:
    int month;
    int day;
}; // required semicolon

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

    DayOfYear today, birthday, obj;
    // These objects need to be globally declared because they are used within different functions
    // so they can't be declared in just one place

    // Also, they needed to be declared after the body of class DayOfYear because the compiler needs
    // to learn what type DayOfYear is first since it goes through the code line by line

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

int main ()
{
    cout << endl;

    // cin >> today.month; 
    // cin >> today.day;
    // are not allowed because the class object can't directly access the private class member

    obj.input (); // Using object obj of class DayOfYear to call the public function input of the same class

    cout << "Today's date is ";
    today.output (); 

    cout << "Your birthday is ";
    birthday.output (); 

    obj.happy_birthday ();
}

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

void DayOfYear :: input ()
{
    cout << "   Please enter today's date." << endl;
    cout<< "================================" << endl;
    cout << "Enter month as a number: ";
    cin >> today.month;
    cout << "Enter the day of the month as a number: ";
    cin >> today.day;
    cout << endl;

    cout << "   Please enter your birthday." << endl;
    cout<< "================================" << endl;
    cout << "Enter the month of your birthday as a number: ";
    cin >> birthday.month;
    cout << "Enter the day of the month as a number: ";
    cin >> birthday.day;
    cout << endl;
}

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

void DayOfYear :: output ()
{
    cout << day << " / " << month << endl;
}

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

void DayOfYear :: happy_birthday ()
{
    if (today.month == birthday.month && today.day == birthday.day)
        cout << endl << "Happy Birthday!" << endl;
    else
        cout << endl << "Happy Unbirthday!" << endl;
}
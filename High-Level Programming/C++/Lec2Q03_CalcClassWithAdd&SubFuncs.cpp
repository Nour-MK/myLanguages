/*
Create a class called Calculator with two integers x and y (as private data members). 
The class also contains Add and Sub member functions (public). 
Write a program that achieves the same task as Question 2. 
Define the functions and call them in the main. 
Feel free to define and declare a get and set functions for the class data members.
In other words, implement question 2 using an object-oriented approach.
*/

#include <iostream>
using namespace std;

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

class Calculator
{
    public:
    int Add ();
    int Sub ();
    void Set ();

    private:
    int x;
    int y;
}; // required semicolon at the end of class block

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

int main ()
{
    Calculator obj;
    
    cout << endl;

    obj.Set(); 
    cout << "The addition of the 2 values is = " << obj.Add () << endl;
    cout << "The subtraction of the 2 values is = " << obj.Sub () << endl;

    // the object in the main is able to access only the public member functions
}

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

int Calculator :: Add ()
{
    return x + y;
}

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

int Calculator :: Sub ()
{
    return x - y;
}

/* ██████████████████████████████████████████████████████████████████████████████████████████████████ */

void Calculator :: Set ()
{
    cout << "Enter the 1st value: ";
    cin >> x;

    cout << "Enter the 2nd value: ";
    cin >> y;
    cout << endl;

    // Note how the class's member functions don't need to use an object to access the
    // member variables, they can call them directly
}
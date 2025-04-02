# include <iostream>
# include <cstring> // needed to use strcpy
using namespace std;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

class student 
{
    private:
            char name [30];
            double metricNo;

    public:
            student (char* studentname, double num) // constructor
            {
                metricNo = num;
                strcpy (name, studentname);
            }

            void print () // member function
            {
                cout << "Student name: " << name << endl;
                cout << "Student metric number: " << metricNo << endl;
            }
};

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    student Student1 ("Mohamed", 152003); // creating object Student1 of class student
    student Student2 ("Saleh", 555555); // creating object Student2 of class student

    cout << "Address of the objects" << endl;
    cout << "Address of Student1: " << &Student1 << endl;
    cout << "Address of Student2: " << &Student2 << endl;

    student* pointer; // creating variable called pointer which is of type pointer to class student
    cout << "Pointer values of the objects" << endl;
    pointer = &Student1; // storing the reference address of object Student1 in the variable pointer
    // & gets the address of the variable in hexadecimal
    cout << "Pointer value for Student1: " << pointer << endl;
    pointer -> print (); // the arrow is one way of accessing a class member through a pointer variable
    pointer = &Student2; // updating the value inside the variable pointer to the reference address of object Student2
    cout << "Pointer value for Student2: " << pointer << endl;
    (*pointer).print (); // this notation is also another way of accessing a class member through a pointer variable

    // The point of this is to show that you can either print the address of an object directly using & operator
    // or you can store the address in a variable and then print


    /*
    // This is an alternative way of doing the whole body of the main (using new and delete operators)

    int main ()
    {
        student* pointer = new student ("Mohamed", 152003); // to allocate memory for the pointer variable
        pointer -> print ();
        delete (pointer); // to destroy the memory of the pointer variable

        pointer = new student ("Saleh", 555555);
        pointer -> print ();
        delete (pointer);
    }
    */
}
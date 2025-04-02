# include <iostream>
using namespace std;

class staff
{
    char name [20]; // cstring
    int age;
    float salary;

    public:
            void read_data () // note how we're defining the function inside the body of the class
            {
                cout << "Type the name: ";
                cin >> name;
                cout << "Type the age: ";
                cin >> age;
                cout << "Type the salary: ";
                cin >> salary;
            }

            void print_data () // note how we're defining the function inside the body of the class
            {
                cout << "The name is " << name << endl;
                cout << "The age is " << age << endl;
                cout << "The salary is " << salary << endl;
            }
}; // remember the semicolon at the end of a class defintion

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    staff manager [20]; // an array of type class
    // This means that this array will contain elements that are objects
    // So this array will contain 20 managers from the staff each one with a name, age, and salary

    for (int index = 0; index < 20; index++) // this for loop is to read all the data of the 20 managers
    {
        cout << "This is manager number " << index << endl;
        manager[index].read_data ();
    }

    for (int index = 0; index < 20; index++) // this for loop is to print all the data of the 20 managers
    {
        cout << "This is manager number " << index << endl;
        manager[index].print_data();
    }

    // Another way that is more specific in the case you don't want to enter the data of all the manager
    // and just want to enter the data of a specific manager, is the following
    int ind;
    cout << "Type in the number of the manager: ";
    cin >> ind;
    manager[ind].read_data ();
    manager[ind].print_data ();
}
# include <iostream>
# include <cstring> // needed in order to use the strcpy function
using namespace std;

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

class book
{
    
    public:
    // Note how all the constructors are functions that have the same name as the class
    // One of the constructors will execute based on the arguments passed in the object creation
    // Typically, constructors have public accessibility so that code outside the class definition 
    // or inheritance hierarchy can create objects of the class.
    // If we declare the constructor as private then we won't be able to create an object (instance)
    // of the class, which means it can be done but it's pretty useless

    // book (); // default constructor
    book (char *BookTitle, double BookPrice); // constructor with 2 arguments
    book (int = 2000); // constructor with parameters and default argument
    // Be careful here that you cannot have both book () and book (int = 2000) operating
    // at the same time because what if the class is called with no arguments passed, which 
    // one of them will execute? Cuz both take no parameters. This is ambiguous
    // The * before the name of the char variable is a pointer

    // Member functions
    void getData (); // function that won't operate unless called
    void print (); // function that won't operate unless called
    float checkPrice () const; // function that won't operate unless called
    char *getAuthor (); // function that won't operate unless called

    // Note how the destructor also has the same name as the class but with a ~ symbol before it.
    // There can only be one destructor with no parameters and no return type.
    // You don't call the destructor, it gets called automatically at the end of the class.
    // Just like with constructors, if you don't create a destructor, the compiler will 
    // automatically create one (that does nothing) for you.
    // It is not possible to define more than one because the destructor is only one way to 
    // destroy the object create by constructor. Hence destructor can-not be overloaded.
    ~book ();

    private:
    // can only be accessed by the class's public functions
    float price;
    int year;
    char author[20], title [25]; // two char arrays, aka 2 cstrings

}; // remember that a semicolon must be added at the end of a class declaration

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

/* 
book :: book ()
{
    price = 11.00;
    year = 2012;
    strcpy (author, "Alex");
    strcpy = (title, "Hello World");
} 
*/

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

book :: book (char *BookTitle, double BookPrice) // class constructor defintion (2)
// note how we didn't write a return type
{
    strcpy (title, BookTitle); 
    // remember that BookTitle value is passed as an argument for one of the constructors
    strcpy (author, "Mark Twain"); // note this method of assigning a value to a cstring
    price = BookPrice;
    year = 2012;
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

book :: book (int y) // class constructor defintion (3)
// note how we didn't write a return type
{
    year = y;
    price = 10.00;
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

void book :: getData () // class member function defintion
// this function is used to set the parameters of the book using the user's input
{
    cout << "Enter author's name: ";
    cin >> author;
    cout << "Enter book title: ";
    cin >> title;
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

float book :: checkPrice () const // class member function definition
// const member function means that you cannot alter the value
{
    return price;
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

void book :: print () // class member function defintion
{
    cout << "Price: " << price << endl;
    cout << "Year: " << year << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "------------------------" << endl;
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

book :: ~book () // class destructor defintion
// a destructor is the last function that is going to be called before an object is destroyed.
// As can be seen, the definition of the destructor can be outside the body of the class it belongs to
{
    cout << "Destroy the book with title " << title;
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════*/

int main (int argc, char *argv[])
// argv and argc are how command line arguments are passed to main().
// The variables are named argc (argument count) and argv (argument vector) by convention, 
// but they can be given any valid identifier: int main(int num_args, char** arg_strings) 
// is equally valid. They can also be omitted entirely, yielding int main(), if you do not 
// intend to process command line arguments.
{
    // Assuming this code does not contain constructor no. 1 because it clashes in operation 
    // with constructor no. 3

    book bookA; // creating object bookA of class book
    // This object will use constructor no. 3
    // It will set price to 10.00 and year to y which wasn't passed so by default it will be 2000
    // no title or author are assigned

    book bookB (2009); // creating object bookB of class book
    // This object will refer to the class using constructor no. 3
    // It will set price to 10.00 and year to 2009, no title or author are assigned

    book bookC ("Tom Sawyer", 99.99); // creating object bookC of class book
    // This object will refer to the class using constructor no. 2
    // It will set the book title to Tom Sawyer and the price to 99.99, the year to 2012 and the 
    // author to Mark Twain

    bookA.print(); // will print price, year, title, and author or the bookA object
    bookB.print();
    bookC.print();

    bookA.getData(); // here we are updating the fields of the bookA object by allowing the user
    // to enter the author and the title of the book
    bookA.print(); // printing everything regarding bookA again to check the changes

    // The class's destructor will now execute. It will start destroying the objects in the order 
    // they were stopped using till the one that was just recently used
    // Last time bookB was used was line 125 to call the print function
    // Last time bookC was used was line 126 to call the print function
    // Last time bookA was used was line 130 to call the print function
    
    // Note that the destructor of an object does not execute once the object is out of use, it execute 
    // once all of the class's objects are out of use, so the destruction of all the class's objects happens
    // in the same step with the respective order of the time the objects had stopped being used
}
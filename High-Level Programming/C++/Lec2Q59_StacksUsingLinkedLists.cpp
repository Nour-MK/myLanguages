# include <iostream>
using namespace std;

// Using the linked list, the number of elements in the stack is not restricted to a certain size
// Thus, isFull () function is unneeded since elements can be pushed onto the stack without limitation

class nodeStack
{
    public: 
    // the default access for data members of classes is private, but we will be using the following data members frequently in all the coming functions so they must be public
    // in order to be able to access them from outside their class scope
            char data;
            nodeStack *next; // a pointer called next that points to something of type nodeStack - it points at the next element in the stack
};

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

class Stack
{
    public:
            void createStack (); // initializing the top pointer to NULL, which indicates the there are no nodes in the stack upon creation
            void push (char); // the insert operation in a stack
            void pop (); // the delete operation in a stack
            void getTop (); // returns the character that is currently at the Top of the stack
            bool isEmpty (); // returns 0 (for false) or 1 (for true) in check whether the stack is empty
            // this is used in case of deleting because you can't delete if there is nothing in the stack
            void print (); // prints all the current nodes in the stack one by one starting from the top

    private:
            nodeStack *top; // a pointer called top that points to something of type nodeStack - it points at the element currently at the top of the stack
};

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack :: createStack ()
{
    top = NULL; // top pointer is pointing at nothing; no nodes in the stack yet
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

bool Stack :: isEmpty ()
{
    return (top == NULL); 
    // if the top is pointing at NULL, the stack is empty and it will return 1 (true)
    // if the top if pointing at a node, the stack is not empty and it will return 0 (false)
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack :: getTop ()
{
    if (isEmpty ()) // if  isEmpty function returns true, meaning the stack is empty
        cout << "Empty Stack!" << endl;
    
    else
        cout << top -> data << endl; // prints the data of top
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack ::  push (char item)
{
    nodeStack *newnode; // a pointer called newnode that points to something of type nodeStack - it points at the current node being pushed onto the stack
    newnode = new (nodeStack); // creates a dynamic variable, takes space from the heap (freestore)

    if (newnode == NULL)
        cout << "Cannot allocate memory.. Freestore is full." << endl; // recommended check to make sure we can create a newnode

    else
    {
        cout << "Pushed " << item << " onto the stack." << endl;
        newnode -> data = item; // the data of newnode will be the item the user passes in the push () function call
        newnode -> next = top; // the next pointer of the new data item will point at the previous value of top
        top = newnode; // stack operates at one end only (the top) so the newest item added to the stack is the new top
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack :: pop ()
{
    nodeStack *deletenode; // a pointer called deletenode that points to something of type nodeStack - it points at the element at the top which will be popped from the stack

    if (isEmpty ()) // if isEmpty function returns true, meaning the stack is empty
        cout << "Cannot pop because the stack is empty." << endl;

    else
    {
        deletenode = top; // deletenode pointer is now pointing where the top pointer is pointing
        cout << "Popped item: ";
        getTop(); // notifying the user what the item being popped is for clarity
        top = deletenode -> next; // or top = top -> next // the new top will be the next item in the stack after the top because the older one will be popped
        delete(deletenode); // now we can delete the older top
    }
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack :: print ()
{
    if (isEmpty ())
        cout << "Current Stack: Empty Stack!" << endl; // notifying the user that there is nothing in the stack to print
    
    else
    {
        cout << "Current stack: ";

        nodeStack *print = top; // a pointer called print that points to something of type nodeStack - it points where the top is pointing

        while (print != NULL) // while the print pointer hasn't yet reached NULL, which is the end of the stack, print the data one after the other
        {
            cout << print -> data << " ";
            print = print -> next;
        }

        cout << endl;

    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

int main () // start execution here
{
    Stack myS; // creating an object of the class Stack so that it can use all the functions and properties of that class
    myS.createStack(); // to set top = -1 at the creation of the stack which will indicate that it's empty upon creation
    myS.push('C'); // calling function push to inserts item C
    myS.push('V'); // calling function push to inserts item V
    myS.print(); // calling function print to display all the current elements in the stack which are (V C)
    cout<<"Top: ";
    myS.getTop(); // calling function getTop which returns the item currently at the top of the stack (V)
    myS.pop(); // calling the function pop to delete the item currently at the top of the stack (V)
    cout<<"Top: ";
    myS.getTop(); // calling function getTop which returns the item currently at the top of the stack (C)
    myS.pop(); // calling the function pop to delete the item currently at the top of the stack (C)
    cout<<"Top: ";
    myS.getTop();// calling function getTop which returns the item currently at the top of the stack (Empty Stack)
    myS.print(); // calling function print to display all the current elements in the stack (Empty Stack)
    myS.push ('A'); // item 1
    myS.push ('B'); // item 2
    myS.push ('C'); // item 3
    myS.push ('D'); // item 4
    myS.push ('E'); // item 5
    myS.push ('F'); // item 6
    myS.push ('G'); // item 7
    myS.push ('H'); // item 8
    myS.push ('I'); // item 9
    myS.push ('J'); // item 10
    myS.push ('K'); // item 11 - Possible using linked list because the size is dynamic and can grow
    myS.push ('L'); // item 12 - Possible using linked list because the size is dynamic and can grow
    myS.push ('M'); // item 13 - Possible using linked list because the size is dynamic and can grow
    myS.push ('N'); // item 14 - Possible using linked list because the size is dynamic and can grow
    myS.print(); // calling function print to display all the current elements in the stack which are (J I H G F E D C B A)
}
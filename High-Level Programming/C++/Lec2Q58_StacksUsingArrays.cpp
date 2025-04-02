# include <iostream>
using namespace std;

const int SIZE = 10; // the given size of the stack
// because this is an array implementation, the size of the array is fixed so we use the keyword const

class Stack
{
    public : // all functions are public so they can be used outside the class
                void createStack(); // initializing the top index to -1, which indicates the stack is empty at the beginning
                void push (char); // the insert operation in a stack
                void pop (); // the delete operation in a stack
                void getTop (); // returns the character that is currently at the Top of the stack
                bool isFull (); // returns 0 (for false) or 1 (for true) in check whether the stack is full - this is used in case of inserting because you can't insert more items if the stack is full (i.e. you can't insert more items than the stack size)
                bool isEmpty (); // returns 0 (for false) or 1 (for true) in check whether the stack is empty - this is used in case of deleting because you can't delete if there is nothing in the stack
                void print (); // this is the added function that will print all the items in the stack
   
    private : // private data members can only be accessed through the functions of the class
                int top; // index for the top of the stack
                char data [SIZE]; // The array that implements the stack
};

/* ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack :: createStack ()
{
    top = -1;
    // top = -1 means the stack is empty
    // top = 0 means the stack has one element
    // top = size -1 means the stack is full
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

bool Stack :: isFull () // This function is only needed in the array implementation of the stack, because if you have a dynamic data structure that can grow and shrink as per your needs with no fixed size, then you will never run out of space to store more data if you want, but this is not the case for array implementation of stacks
{
    return (top == SIZE -1); // because our array size is 10, this function will return true in the case that the top is 9
    // This function will return false if there is still space in the array to push (insert) items
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

bool Stack :: isEmpty ()
{
    return (top == -1); // if top is index 0 then there is one element in the stack and if top is 1 then there is 2 elements in the stack and so on, so if the top is -1 then there are no elements in the stack 
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack :: push (char Item) // you must specify what item you are inserting onto the stack
{
    if (isFull ()) // check if true
        cout << "Cannot push " << Item << " because the stack is full!" << endl;
    
    else
    {
        top++; // the top index moves to the next point
        // Note how top is increased BEFORE an item is inserted at the index, because if not, then first item will be inserted at the current top value which will mess things up
        data [top] = Item; // the data at the index is set to the character passed in the argument when calling the push function
        cout << Item << " is pushed onto the stack." << endl;
    }
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack :: pop () // no need to specify what item is being deleted from the stack, since the deletion can only happen at one place (the top) then the item there will be deleted whatever it is
{
    if (isEmpty ())
        cout << "Empty Stack!" << endl;
    
    else
    {
        cout << "Popped item: " << data [top] << endl; // to display the item at the top of the stack that is about to get deleted
        top--; // adjusting the index of top - since we are deleting an item then it will be reduced
    }
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack :: getTop ()
{
    if (isEmpty ()) // if this condition is true
        cout << "Empty Stack!" << endl;

    else
        cout << data [top] << endl;
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Stack :: print ()
{
    // since this is an array implementation of the stack
    // then displaying all the elements in the stack is as simple as using a for loop to print the element at every index

    if (isEmpty ())
        cout << "Current Stack: Empty Stack!" << endl; // notifying the user that there is nothing in the stack to print
    
    else
    {
        cout << "Current stack: ";

        for (int index = top; index >= 0; index--)
        {
            cout << data [index] << " ";
        }
        
        cout << endl;
    }
}

/* ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

int main() // driver main function 
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
    myS.push ('K'); // item 11 - Not possible using the array because it exceeds the predefined fixed size
    myS.push ('L'); // item 12 - Not possible using the array because it exceeds the predefined fixed size
    myS.push ('M'); // item 13 - Not possible using the array because it exceeds the predefined fixed size
    myS.push ('N'); // item 14 - Not possible using the array because it exceeds the predefined fixed size
    // Keep in mind: Any push after 10, should display stack is full when the array is used. 
    myS.print(); // calling function print to display all the current elements in the stack which are (J I H G F E D C B A)
}
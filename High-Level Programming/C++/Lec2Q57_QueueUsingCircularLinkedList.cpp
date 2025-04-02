# include <iostream>
using namespace std;

// Difference is in the body of the class Queue, CreateQueue (), DestroyQueue (), isEmpty (), enQueue (), deQueue ()

struct QueueNode // default access mode is public
{
    char item;
    QueueNode *next; // pointer called next
};

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

class Queue
{
    public:
            QueueNode *BackPtr; // No need for FrontPtr since we can replace it with BackPtr -> next since the end of the list is connected (looping back) to the beginning
            int counter; // to count how many nodes there are in the queue
            void CreateQueue ();
            void DestroyQueue ();
            bool isEmpty ();
            void enQueue (char);
            void deQueue ();
            void PrintQueue ();
            void GetRear ();
};

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: CreateQueue ()
{
    // Upon queue creation, there are no nodes yet, so the back and front pointers have nothing to point at.
    BackPtr = NULL;
    counter = 0;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: DestroyQueue ()
{
    QueueNode *temp = BackPtr -> next; // the te,p pointer points at the start of the list because the next of the last node is the first node because this is a circular list

    while (temp) // In other words, while temp pointer is not pointing at NULL (hasn't reached the end of the queue)
    {
        BackPtr -> next = BackPtr -> next -> next;
        delete temp;
        temp = BackPtr -> next;
    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

bool Queue :: isEmpty ()
{
    if (BackPtr == NULL)
        return 1;
    
    else
        return 0;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: enQueue (char item)
{
    // Inserting a new node into a queue has 2 cases:
    // 1. Inserting in an empty queue
    // 2. Inserting in a non-empty queue

    cout << "Operation: Insert " << item << " to queue." << endl;

    QueueNode *NewNode = new QueueNode;

    if (isEmpty ()) // if the queue is empty
    {
        NewNode -> item = item;
        NewNode -> next = NewNode; // self loop
        BackPtr = NewNode;
    }

    else // if the queue is not empty
    {
        NewNode -> item = item;
        NewNode -> next = BackPtr -> next;
        BackPtr -> next = NewNode;
        BackPtr = NewNode;
    }

    counter++;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: deQueue ()
{
    // In queue, deletion happens at the front

    // Deletion cases:
    // 1. Deleting from a regular queue
    // 2. Deleting from a queue than contains one node only

    cout << "Operation: Delete " << (BackPtr -> next) -> item << " from queue." << endl;

    QueueNode *DeleteNode = new QueueNode;
    DeleteNode = BackPtr -> next;

    if (isEmpty ())
    {
        cout << "Cannot delete, the queue is empty." << endl;
    }

    else // if the queue is not empty, then there are items to delete
    {
        if (DeleteNode == BackPtr) // means if the queue contains 1 item only - in other words, the delete node and the back pointer are both pointing at the same node
        {
            BackPtr = NULL;
            delete DeleteNode; // we delete what the pointer is pointing towards, not the pointer itself
        }

        else // means if the queue contains more than 1 item 
        {
            BackPtr -> next = DeleteNode -> next;
            delete DeleteNode;
        }

        counter--;
    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: PrintQueue ()
{
    if (isEmpty ())
        cout << "Current Queue: Empty Queue!" << endl; // notifying the user that there is nothing in the stack to print
    
    else
    {
        cout << "Current Queue: ";

        QueueNode *print = new QueueNode;
        print = BackPtr -> next;

        for (int index = 0; index < counter; index++)
        {
            cout << print -> item << " ";
            print = print -> next;
        }

        cout << endl;

    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: GetRear ()
{
    if (isEmpty ())
    {
        cout << "NULL" << endl;
    }

    else 
    {
        cout << BackPtr -> item << endl;
    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    Queue myQueue; // creating an object called myQueue of type class Queue

    myQueue.CreateQueue ();
    myQueue.PrintQueue();
    cout << "Array Indexes: ";
    if (myQueue.isEmpty())
        cout << "Empty Queue!" << endl;
    else
    {
        for (int index = 0; index <= myQueue.counter; index++)
        {
            cout << index << " ";
        }
        cout << endl;
    }
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;

    myQueue.enQueue('N');
    myQueue.PrintQueue();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;

    myQueue.deQueue();
    myQueue.PrintQueue();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;

    myQueue.enQueue('M');
    myQueue.PrintQueue();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;

    myQueue.enQueue('K');
    myQueue.PrintQueue();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;

    myQueue.enQueue('H');
    myQueue.PrintQueue();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;
}
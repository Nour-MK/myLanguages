# include <iostream>
using namespace std;

struct QueueNode // default access mode is public
{
    char item;
    QueueNode *next; // pointer called next
};

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

class Queue
{
    public:
            QueueNode *BackPtr, *FrontPtr;
            int counter; // to count how many nodes there are in the queue
            void CreateQueue ();
            void DestroyQueue ();
            bool isEmpty ();
            void enQueue (char);
            void deQueue ();
            void PrintQueue ();
            void GetFront ();
            void GetRear ();
};

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: CreateQueue ()
{
    // Upon queue creation, there are no nodes yet, so the back and front pointers have nothing to point at.
    BackPtr = NULL;
    FrontPtr = NULL;
    counter = 0;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: DestroyQueue ()
{
    QueueNode *temp = FrontPtr;

    while (temp) // In other words, while temp pointer is not pointing at NULL (hasn't reached the end of the queue)
    {
        FrontPtr = temp -> next;
        delete temp;
        temp = FrontPtr;
    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

bool Queue :: isEmpty ()
{
    if (BackPtr == NULL && FrontPtr == NULL) // or (!BackPtr && !FrontPtr)
        return 1;
    
    else
        return 0;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: enQueue (char item)
{
    // Inserting a new node at the back needs 3 pointer changes:
    // 1. Change next pointer in the new node
    // 2. Change the next pointer in the back node
    // 3. Change the external pointer

    // Inserting a new node into a queue has 2 cases:
    // 1. Inserting in an empty queue
    // 2. Inserting in a non-empty queue

    cout << "Operation: Insert " << item << " to queue." << endl;

    QueueNode *NewNode = new QueueNode;

    if (isEmpty ()) // if the queue is empty
    {
        NewNode -> item = item;
        NewNode -> next = NULL;
        FrontPtr = BackPtr = NewNode;
    }

    else // if the queue is not empty
    {
        NewNode -> item = item;
        NewNode -> next = NULL;
        BackPtr -> next = NewNode;
        BackPtr = NewNode;
    }

    counter++;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: deQueue ()
{
    // In queue, deletion happens at the front
    // Only one pointer change is needed

    // Deletion cases:
    // 1. Deleting from a regular queue
    // 2. Deleting from a queue than contains one node only

    cout << "Operation: Delete " << FrontPtr -> item << " from queue." << endl;

    QueueNode *DeleteNode = new QueueNode;

    if (isEmpty ())
    {
        cout << "Cannot delete, the queue is empty." << endl;
    }

    else // if the queue is not empty, then there are items to delete
    {
        if (FrontPtr -> next == NULL) // means if the queue contains 1 item only - in other words, the delete node and the front pointer and the back pointer are all pointing at the same node
        {
            DeleteNode = FrontPtr;
            FrontPtr = NULL;
            BackPtr = NULL;
            delete DeleteNode;
        }

        else // means if the queue contains more than 1 item 
        {
            DeleteNode = FrontPtr; // the delete node pointer points where the front pointer is pointing, because we delete from the front
            FrontPtr = FrontPtr -> next; // the front pointer now points at the next element in the queue because the first is about to be deleted
            DeleteNode -> next = NULL; // isolating the first node to be deleted by removing its next pointer from pointing at the second item in the queue
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
        print = FrontPtr; // a pointer called print that points to something of type QueueNode - it points where the front pointer is pointing

        while (print != NULL) // while the print pointer hasn't yet reached NULL, which is the end of the stack, print the data one after the other
        {
            cout << print -> item << " ";
            print = print -> next;
        }

        cout << endl;

    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: GetFront ()
{
    if (isEmpty ())
    {
        cout << "NULL" << endl;
    }

    else
    {
        cout << FrontPtr -> item << endl;
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
    cout << "Front = ";
    myQueue.GetFront();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;

    myQueue.deQueue();
    myQueue.PrintQueue();
    cout << "Front = ";
    myQueue.GetFront();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;

    myQueue.enQueue('M');
    myQueue.PrintQueue();
    cout << "Front = ";
    myQueue.GetFront();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;

    myQueue.enQueue('K');
    myQueue.PrintQueue();
    cout << "Front = ";
    myQueue.GetFront();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;

    myQueue.enQueue('H');
    myQueue.PrintQueue();
    cout << "Front = ";
    myQueue.GetFront();
    cout << "Back = ";
    myQueue.GetRear();
    cout << "Number of items in queue: " << myQueue.counter << endl;
    cout << "================================" << endl;
}
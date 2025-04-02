# include <iostream>
using namespace std;

const int SIZE = 2;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

class Queue
{
    private :
              int front; // index at front of the queue (not the array)
              int back; // index at end of the queue (not the array)
              char items [SIZE]; // array called items of type character and size 2
    public :
              Queue (); // constructor - create a queue
              ~Queue (); // destructor - destroy the queue
              bool isEmpty (); // function to check whether the queue is empty before deleting
              bool isFull (); // function to check whether the queue is full before inserting
              void enQueue (char); // function to insert an item of type character into the queue
              void deQueue (); // function to delete an item from the queue
              int getFront (); // function to get the item at the front of the queue
              int getRear (); // function to get the item at the back of the queue
              void printQueue (); // function to print the queue

}; // Remember the required semicolon at the end of the class definition

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

Queue :: Queue () // class constructor definition
{
    // These are the initial conditions for creating a queue
    // They mean we have created an empty queue
    front = 0;
    back = -1;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

Queue :: ~Queue () // class destructor definition
{
    // all elements in the queue will be disposed
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

bool Queue :: isEmpty ()
// Returns true if the queue is empty
// Returns false if the queue is not empty
{
    return bool(back < front);
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

bool Queue :: isFull ()
// Returns true if the queue is full
// Returns false if the queue is not full
{
    return bool(back == SIZE - 1); // size-1 is the index of the last item in the array, 2 is the size
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: enQueue (char item)
{
    cout << ">> Operation on queue: Insert " << item << " to the back of the queue." << endl;

    if (isFull())
    {
        cout << "Cannot insert item. Queue is Full!" << endl;
    }

    else 
    {
        back++; // In queues, we insert at the back, so the back increases by 1
        items [back] = item; // inserting the item at the back of the queue
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: deQueue ()
{
    cout << ">> Operation on queue: Delete " << items[front] << endl;

    if (isEmpty ())
    {
        cout << "Queue is empty. There's nothing to delete." << endl;
    }

    else
    {
        front++; // In queues, we delete from the front, so the front increases by 1
        // the queue is an instance of the array
        // so we can simply make the queue consider a new starting point for itself from the array
        // We didn't actually delete the item from the array, we made the queue think the array starts 
        // from a later index than the actual index
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int Queue :: getFront ()
{
    return front;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int Queue :: getRear ()
{
    return back;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: printQueue ()
{
    if (isEmpty ())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue: ";
        for (int index = front; index <= back; index++)
        {
            cout << items [index] << " ";
        }
        cout << endl;

        cout << "Index: ";
        for (int index = front; index <= back; index++)
        {
            cout << index << " ";
        }
        cout << endl;
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    Queue myQueue; // creating an object called myQueue of type class Queue

    myQueue.printQueue();
    cout << "Array Indexes: ";
    for (int index = 0; index < SIZE; index++)
    {
        cout << index << " ";
    }
    cout << endl;
    cout << "================================" << endl;

    myQueue.enQueue('N');
    myQueue.printQueue();
    cout << "Front index = " << myQueue.getFront() << endl;
    cout << "Back index = " << myQueue.getRear() << endl;
    cout << "================================" << endl;

    myQueue.deQueue();
    myQueue.printQueue();
    cout << "Front index = " << myQueue.getFront() << endl;
    cout << "Back index = " << myQueue.getRear() << endl;
    cout << "================================" << endl;

    myQueue.enQueue('M');
    myQueue.printQueue();
    cout << "Front index = " << myQueue.getFront() << endl;
    cout << "Back index = " << myQueue.getRear() << endl;
    cout << "================================" << endl;

    myQueue.enQueue('K');
    myQueue.printQueue();
    cout << "Front index = " << myQueue.getFront() << endl;
    cout << "Back index = " << myQueue.getRear() << endl;
    cout << "================================" << endl;

    myQueue.enQueue('H');
    myQueue.printQueue();
    cout << "Front index = " << myQueue.getFront() << endl;
    cout << "Back index = " << myQueue.getRear() << endl;
    cout << "================================" << endl;
}
# include <iostream>
using namespace std;

const int MAX_QUEUE = 2;

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

class Queue
{
    private :
              int front; // index at front of the queue (not the array)
              int back; // index at end of the queue (not the array)
              int counter; // 
              char items [MAX_QUEUE]; // array called items of type character and size 2
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
    counter = 0;
    front = 0;
    back = MAX_QUEUE - 1;
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
    return bool(counter == 0);
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

bool Queue :: isFull ()
// Returns true if the queue is full
// Returns false if the queue is not full
// REMEMBER that even if it's a circular array, it could get full if there are items at every position in the array (since it has a limited size after all)
// The circular array method only helps avoid the rightward drifting issue
{
    return bool(counter == MAX_QUEUE); 
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

void Queue :: enQueue (char item)
{
    cout << ">> Operation on queue: Insert " << item << " to the back of the queue." << endl;

    if (isFull())
    {
        cout << "Cannot insert item. Queue is Full!" << endl;
    }

    else // if it's not full then we can start inserting
    {
        back = (back + 1) % MAX_QUEUE; // the mod operator is used to achieve the wrap around effect
        items [back] = item;
        counter++;
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

    else // if it's not empty then we can start deleting
    {
        front = (front + 1) % MAX_QUEUE;
        counter--;
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
        int index1 = front;
        while (index1 != back)
        {
            cout << items [index1] << " ";
            index1 = (index1 + 1) % MAX_QUEUE;
        }
        cout << items [back] << endl;


        cout << "Index: ";
        int index2 = front;
        while (index2 != back)
        {
            cout << index2 << " ";
            index2 = (index2 + 1) % MAX_QUEUE;
        }
        cout << back << endl;
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    Queue myQueue; // creating an object called myQueue of type class Queue

    myQueue.printQueue();
    cout << "Array Indexes: ";
    for (int index = 0; index < MAX_QUEUE; index++)
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
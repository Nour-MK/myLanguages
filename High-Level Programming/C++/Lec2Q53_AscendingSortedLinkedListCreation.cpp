# include <iostream>
using namespace std;

class Node
{
    public: 
    // they must be public because they will be frequently used in all the functions which means they will be called 
    // outside of this class and if they were not set to public they will be private by default
            
    // Each node in the linked list contains a data field which will store some value in the node and a pointer to the next node
            int data; // change the int into any type depending on the type of data stored in the linked list
            Node *next; // a pointer called next which will point at the next node in the list
    
    // KEEP IN MIND that you can also declare a node using a struct instead of a class
    // Remember that the default access mode of structs is public, so the data members don't need to be explicitly declared as public
    // For example, if we were creating a node for a bank, this node will likely have more than 2 fields like: AccountName, AccountNumber, Balance, and *next
};

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

class List
{
    public: 
            List (); // constructor - it creates the list
            ~List (); // destructor - it destroys the list

            // The following functions help in performing operations on the linked list:
            bool isEmpty (); // Function 1: to determine whether or not the list is empty
            int FindNode (int x); // Function 2: to find a node with a given value
            void InsertNode (int x); // Function 3: to insert a new node at a particular position
            void DeleteNode (int x); // Function 4: to delete a node with a given value
            void DisplayList (); // Function 5: to print all the nodes in the list

    private:
            Node *head; // a pointer called head which points at something of type Node - specifically, it points to the first node in the list
            int length; // to track the number of nodes in the list
};

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

List :: List ()
{
    // Once the list is created, it's initially empty with no nodes in it, so the head is NULL and the length (aka the number of nodes) is 0
    head = NULL;
    length = 0;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

List :: ~List ()
{
    Node *CurrentNode = head; // setting the current node pointer to point where the head pointer is pointing
    // because we will be deleting each node in the list one by one starting from the head all the way to the end (NULL)
    Node *NextNode = NULL; // a temporary pointer which will be used to store what the next pointer of the current node is pointing at before changing the current node to the next node

    while (CurrentNode != NULL) // while we haven't yet reached the end of the list
    {
        NextNode = CurrentNode -> next;
        delete CurrentNode;
        CurrentNode = NextNode;
    }

    head = NULL; // setting the head pointer to NULL to indicate that the list is empty, containing no nodes
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

bool List :: isEmpty ()
{
    if (head == NULL) // or we could say if length == 0
        return 1; // meaning true - that the list is empty
    
    else
        return 0; // meaning false - that the list is not empty
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

int List :: FindNode (int x)
{
    Node *CurrentNode = head;
    int CurrentIndex = 1; // the current index we start searching from is the 1st item

    while (CurrentNode != NULL && CurrentNode -> data != x) 
    // means if the list is not finished (at the end) and if the data pointed at by the current node is not the value being search for
    {
        CurrentNode = CurrentNode -> next; // make the current node pointer point at the next item in the list 
        CurrentIndex++; // now the current index we're at is the next item in the list 
    }

    if (CurrentNode != NULL)
        return CurrentIndex; // returning the index of the item being searched for
    
    else
        return 0; // if the item being searched for does not exist then we return 0
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void List :: InsertNode (int x)
{
    // There are 3 possible insertion cases:
    // 1. Inserting into an empty list - which means the insertion will happen at the head
    // 2. Inserting into a list with some nodes in it - which means the insertion will happen at the back
    // 3. Inserting at a specific position - which means the insertion will happen at the middle

    Node *CurrentNode = head; // a pointer called CurrentNode that points at something of type Node - specifically, it points where the head of the list is pointing
    Node *PreviousNode = NULL; // a pointer called PreviousNode that points at something of type Node - specifically, it points at nothing, assuming that we are at the 
    // start of the list then there is no previous node because the current node is the head which is the start of the whole list so there is nothing before it

    while (CurrentNode != NULL && x > CurrentNode -> data) 
    // If the list is not empty and the item to be inserted is greater in value that the item in the current node
    // This is the condition because this is an ascending sorted list, so :
    // If the item to be inserted is greater than the current node then the insertion happens at the back or middle
    // If the item to be inserted is smaller than the current node then the insertion happens at the front
    {
        PreviousNode = CurrentNode; // now the previous node points where the current node is pointing 
        CurrentNode = CurrentNode -> next; // now the current node is pointing where its next pointer is pointing
    }

    Node *NewNode = new Node; // a pointer called NewNode that points at something of type Node and we are allocating memory for the new node
    NewNode -> data = x; // putting the value of the item passed when calling the function in the data field of the new node that was created 

    if (PreviousNode == NULL) // it means if the insertion is happening at the front (head) of the list - CAREFUL THIS DOESN'T MEAN WE'RE INSERTING ONTO AN EMPTY LIST
    {
        // Steps:
        // 1. pointing the new node to its successor (what comes after it) - if it's at the back them the successor is NULL
        // 2. pointing the new node's predecessor (what comes before it) to the new node

        NewNode -> next = head; // the next pointer of the new node is pointing where the head pointer is pointing
        // this makes the older head of the list become the second item after it used to be the head because the new node will be the new head because we are inserting at the front of the list 
        head = NewNode; // now the head points where the new node is pointing
    }

    else // it means if the insertion is happening in the middle of the list (between the previous and the current)
    {
        // Steps:
        // 1. pointing the new node to its successor (what comes after it) - if it's at the back them the successor is NULL
        // 2. pointing the new node's predecessor (what comes before it) to the new node

        NewNode -> next = PreviousNode -> next; // the next pointer of the new node is pointing where the next pointer of the previous node is pointing
        PreviousNode -> next = NewNode; // the next pointer of the previous node is now pointing at the new node
    }

    length++; // since we added a node to the list, then its length is increased by 1
    cout << "Node " << x << " is inserted into the list." << endl;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void List :: DeleteNode (int x)
{
    // There are 2 possible deletion cases:
    // 1. Deleting the first node in the list
    // 2. Deleting the node in the middle or at the end of the list

    Node *PreviousNode = NULL; // when the current node is head then the previous node is NULL because there are no items before the head of the list
    Node *CurrentNode = head; // starting the search from the head all the way to the end of the list (NULL)
    int CurrentIndex = 1; // starting the search from the head (of index 1)

    while (CurrentNode && CurrentNode -> data != x) // Finding the node (containing data x) to be deleted
    {
        PreviousNode = CurrentNode; // Now the previous node pointer points at the next item in the list which is current node
        CurrentNode = CurrentNode -> next; // Now the current node pointer points at the next item in the list
        CurrentIndex++; // now the index is of the next item in the list
    }

    if (CurrentNode) // means if CurrentNode is any value but NULL - in other words if the searching for the node did not lead us to the end of the list (which is NULL) without finding the item
    {
        if (PreviousNode) // if PreviousNode is any value but NULL, then the deletion is happening at either the middle or the end of the list
        {
            PreviousNode -> next = CurrentNode -> next; // set the pointer of the predecessor of the found node to the successor of the found node
            delete CurrentNode; // releasing the memory occupied by the found node
        }

        else // if PreviousNode is NULL, then the deletion is happening at the first node of the list 
        {
            head = CurrentNode -> next; // set the pointer of the predecessor of the found node to the successor of the found node
            delete CurrentNode; // releasing the memory occupied by the found node
        }

        cout << "Node " << x << " is deleted from the list." << endl; // notifying the user which node has been deleted for clarity
        length--; // now there is one less node in the list so the length is decremented by 1
    }

    else // if the search for the node failed and the current node moved all the way to the end of the list (to NULL) without finding the item
    {
        cout << "Node " << x << " is not in the list." << endl;
    }
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void List :: DisplayList ()
{
    Node *CurrentNode = head; 
    // setting the CurrentNode pointer to point where the head pointer is pointing because we will print all the items if the list starting from the head all the way to the end (NULL)

    cout << "List: ";
    while (CurrentNode != NULL) // while we haven't reached the end of the list
    {
        cout << CurrentNode -> data << "  ";
        CurrentNode = CurrentNode -> next;
    }
    cout << endl;

    cout << "Number of the nodes in the list: " << length << endl;
}

/* ═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    List LinkedList; // creating object linkedlist that belongs to class List so that it can use all the functions provided by that class

    LinkedList.InsertNode(88); // insert to empty list - so insertion happens at the head
    LinkedList.InsertNode(5); // insert to the head because 5 is smaller than 88
    LinkedList.InsertNode(16); // insert to middle because 16 is greater than 5 and smaller that 88
    LinkedList.DisplayList(); // Note how even though the order of inserting the values into the list is 88 - 5 - 16 the display will print 5 - 16 - 88
    // because those items are inserted into their correct positions in context with the ascending order of the list which is controlled by the InsertNode function

    int value;
    cout << "What value are you searching for? ";
    cin >> value;
    if (LinkedList.FindNode (value) > 0)
        cout << value << " is found at index " << LinkedList.FindNode (value) << endl;
    else
        cout << value << " is not in the list." << endl;
    
    LinkedList.DeleteNode(88);
    LinkedList.DisplayList();
}
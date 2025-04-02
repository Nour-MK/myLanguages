# include <iostream>
using namespace std;

struct TreeNode // 3 components of a node
// Node that we could also create TreeNode using a class but we'd have to declare the data members as public because they will be frequently used outside the class
{
    char info; // a node that stores a char value
    TreeNode *LeftPtr; // a pointer caller LeftPtr that points at the left subtree
    TreeNode *RightPtr; // a pointer called RightPtr that points at the right subtree
};

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

class Tree
{
    public:
            Tree (); // constructor to initialize the tree
            ~Tree (); // destructor to destroy the tree after the program finishes to free the memory that was occupied by it
            void Destroy (TreeNode *&); // will be called recursively by the destructor
            bool isEmpty (); // to check whether the tree ie empty or has nodes in it
            void RetrieveItem (char); // to search for an item in the tree
            void Retrieve (TreeNode *, char &, bool &); // will be called recursively by the RetrieveItem function
            void InsertItem (char); // to insert an item into the tree
            void Insert (TreeNode *&, char); // will be called recursively by the InsertItem function
            void DeleteItem (char); // to delete an item from the tree
            TreeNode* Delete (TreeNode *, char); // will be called recursively by the DeleteItem function
            TreeNode* FindMin (TreeNode *); // will be called by the Delete function
            void PrintTree (); // to print all items in the tree using in-order traversal
            void PrintInOrder (TreeNode *tree); // will be called recursively by the PrintTree function
            void PrintPreOrder (TreeNode *tree); // will be called recursively by the PrintTree function
            void PrintPostOrder (TreeNode *tree); // will be called recursively by the PrintTree function
            char PrintRoot ();

    private:
            TreeNode *root; // a pointer called root that points at the first element in the tree (you can go anywhere from the root)
            int counter; // to count the number of nodes in the tree
}; 

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

Tree :: Tree ()
{
    root = NULL; // creating an empty tree with no nodes so the root points at nothing because there's nothing to point at
    counter = 0; // initially, there are 0 nodes in the tree
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

Tree :: ~Tree () // it will destroy all the nodes in the tree
{
    Destroy (root);
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: Destroy (TreeNode *&tree)
{
    if (tree != NULL)
    {
        Destroy (tree -> LeftPtr); // recursive call - destroy everything in the left subtree first
        Destroy (tree -> RightPtr); // recursive call - destroy everything in the right subtree second
        delete (tree); // destroy the root itself
    }

    // Example of the implementation: https://iili.io/HvbWnV4.png
    // Destructions in order: A - J - G - Y - P - M
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

bool Tree :: isEmpty ()
{
    if (root == NULL) // if the root is not pointing at any node then the tree is empty
        return 1;
    
    else
        return 0;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: RetrieveItem (char item)
{
    // Three searching cases:
    // 1. If the item being searched for is the root.
    // 2. If the item being searched for is less than the root, then the searching will be at the left subtree.
    // 3. If the item being searched for is greater than the root, then the searching will be at the right subtree.

    bool found = false;
    Retrieve (root, item, found); // function call
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: Retrieve (TreeNode *tree, char &item, bool &found)
{
    if (tree == NULL) // if the tree is empty - this is a base case
    {
        found = false;
        cout << "Item not found." << endl;
    }

    else if (item < tree -> info)
        Retrieve (tree -> LeftPtr, item, found); // recursive call

    else if (item > tree -> info)
        Retrieve (tree -> RightPtr, item, found); // recursive call
    
    else // this is a base case
    {
        found = true;
        cout << "Item is found." << endl;

        // To determine what is the type of node found is:

        if ((tree -> LeftPtr == NULL) && (tree ->RightPtr == NULL))
            cout << tree -> info << " is a leaf node." << endl;

        else if ((tree -> LeftPtr != NULL) && (tree -> RightPtr != NULL))
        {
            cout << tree -> info << " has two children: " << endl;
            cout << "On the left: " << (tree -> LeftPtr) -> info << endl;
            cout << "On the right: " << (tree -> RightPtr) -> info <<  endl;
        }

        else if (tree ->  LeftPtr != NULL)
            cout << tree -> info << " has one child: " << (tree -> LeftPtr) -> info << " on the left." << endl;

        else
            cout << tree -> info << " has one child: " << (tree -> RightPtr) -> info << " on the right." << endl;
    }

}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: InsertItem (char item)
{
    // Before a node can be inserted into a binary search tree, the position of the new node must be determined.
    // This is to ensure that after the insertion, the binary search tree characteristics are still maintained.

    Insert (root, item); // function call
    counter++;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: Insert (TreeNode *& tree, char item)
{
    if (tree == NULL) // case: if we're inserting to an empty tree
    {
        tree = new TreeNode;
        tree -> RightPtr = NULL;
        tree -> LeftPtr = NULL;
        tree -> info = item;
    }

    else if (item < tree -> info) // case: if we're inserting to a non-empty tree and the item to be inserted is less than the value root
        Insert (tree -> LeftPtr, item); // recursive call
    
    else // case: if we're inserting to a non-empty tree and the item to be inserted is greater than the value of the root
        Insert (tree -> RightPtr, item); // recursive call
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: DeleteItem (char item)
{
    // When a node is deleted, the children of the deleted node must be taken care of to ensure that the property of the BST is maintained.

    // Three possible deletion cases:
    // 1. Delete a leaf - adjust the pointer in its parent to NULL and delete it immediately
    // 2. Delete a node with one child - adjust the pointer from the parent to bypass that node and connect directly to its child
    // 3. Delete a node that has 2 children - locate another node that is easier to delete (the leftmost i.e. smallest node in the right subtree of the node to be deleted, and that node has no more than 1 child, and it is a successor of the node to be deleted) then copy that node to the node to be deleted and delete that node
    // Keep in mind that we say the easier node to delete is one that has either no child or just one right child because if it has a left child, that left child would be smaller and would have been chosen

    Delete (root, item); // function call

}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

TreeNode* Tree :: Delete (TreeNode *tree, char item)
{
    if (tree == NULL)
        return tree;
    
    else if (item < tree -> info)
        tree -> LeftPtr = Delete (tree -> LeftPtr, item);

    else if (item > tree -> info)
        tree -> RightPtr = Delete (tree -> RightPtr, item);

    else
    {
        if ((tree -> LeftPtr == NULL) && (tree -> RightPtr == NULL)) // no child
        {
            delete tree;
            tree = NULL;
        }

        else if (tree -> LeftPtr == NULL) // one child on the right
        {
            TreeNode *temp = new TreeNode;
            temp = tree;
            tree = tree -> RightPtr;
            delete temp;
        }

        else if (tree -> RightPtr == NULL) // one child on the left
        {
            TreeNode *temp = new TreeNode;
            temp = tree;
            tree = tree -> LeftPtr;
            delete temp;
        }

        else // two children
        {
            TreeNode *temp = new TreeNode;
            temp = FindMin (tree -> RightPtr); // function call
            tree -> info = temp -> info;
            tree -> RightPtr = Delete (tree -> RightPtr, temp -> info);
        }
    }

    return tree;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

TreeNode* Tree :: FindMin (TreeNode *tree) // to find the minimum in a tree
{
    while (tree -> LeftPtr != NULL)
        tree = tree -> LeftPtr;
    
    return tree;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: PrintTree ()
{
    cout << "In-order:  ";
    PrintInOrder (root); // function call
    cout << endl;

    cout << "Pre-order:  ";
    PrintPreOrder (root); // function call
    cout << endl;

    cout << "Post-order:  ";
    PrintPostOrder (root); // function call
    cout << endl;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: PrintInOrder (TreeNode *tree) // Printing in-order (left node - root - right node)
{
    if (tree != NULL) // meaning if the tree is not empty or if we haven't yet reached the end of the tree
    {
        PrintInOrder (tree -> LeftPtr); // recursive call
        cout << tree -> info << " ";
        PrintInOrder (tree -> RightPtr); // recursive call
    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: PrintPreOrder (TreeNode *tree) // Printing pre-order (root - left node - right node)
{
    if (tree != NULL) // meaning if the tree is not empty or if we haven't yet reached the end of the tree
    {
        cout << tree -> info << " ";
        PrintPreOrder (tree -> LeftPtr); // recursive call
        PrintPreOrder (tree -> RightPtr); // recursive call
    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

void Tree :: PrintPostOrder (TreeNode *tree) // Printing post-order (left node - right node - root)
{
    if (tree != NULL) // meaning if the tree is not empty or if we haven't yet reached the end of the tree
    {
        PrintPostOrder (tree -> LeftPtr); // recursive call
        PrintPostOrder (tree -> RightPtr); // recursive call
        cout << tree -> info << " ";
    }
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

char Tree :: PrintRoot ()
{
    return root -> info;
}

/* ═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

int main ()
{
    Tree obj; // the tree constructor will be called by default the second we created this object, so no need to explicitly call it
    int number;
    char item, searchkey, deletekey;

    cout << "How many nodes do you want to insert? ";
    cin >> number;

    for (int i = 1; i <= number; i++)
    {
        cout << "Insert node #" << i << ": ";
        cin >> item;
        obj.InsertItem (item);
    }

    obj.PrintTree ();
    cout << "Root: " << obj.PrintRoot() << endl;

    cout << "What item are you searching for? ";
    cin >> searchkey;
    obj.RetrieveItem(searchkey);

    cout << "What item would you like to delete? ";
    cin >> deletekey;
    obj.DeleteItem (deletekey);

    obj.PrintTree();
    cout << "Root: " << obj.PrintRoot() << endl;
}
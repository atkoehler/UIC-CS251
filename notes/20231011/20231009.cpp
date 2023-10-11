/// @file 20231011.cpp
/// @author Adam T Koehler, PhD
/// @date October 11, 2023
/// @brief Class code and notes from the lecture. This code utilizes
///         a linked list class alongside with helper functions to 
///         implement sorting algorithms: insertion sort and selection sort.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include <iostream> // console output
#include <random>   // used for random list data generation

using namespace std;

// basic node setup for our Linked List
struct Node
{
    int data;
    Node* next;
};

// Super basic linked list class
class List
{
    private:
        Node* front;
        size_t sz;

    public:
        List();
        Node* getFront() const;
        void setFront(Node*);
        size_t size() const;
        void incrementSize();

};


// Prototypes for the various functions.
// Remember, variable names are not required for prototypes

// List creation and viewing helpers
void buildList(List &, size_t);
void printList(const List &);

// sort algorithm helpers
Node* findPrev(const List &, Node *);
Node* findMin(Node *);
void swap(List &, Node*, Node*);

// sorting algorithms
void sortList(List &);
void insertionSort(List &);
void selectionSort(List &);


// main function to just demo some of our functions
int main()
{
    srand(time(0));
    const int N = 7;
    List m;

    cout << "Building a list of " << N << " items." << endl;
    buildList(m, N);

    cout << "Printing..." << endl;
    printList(m);

    cout << "Swapping second and fifth elements..." << endl;
    swap(m, m.getFront()->next, m.getFront()->next->next->next->next);
    printList(m);

    cout << "Swapping second and third elements..." << endl;
    swap(m, m.getFront()->next, m.getFront()->next->next);
    printList(m);

    cout << "Swapping first and second elements..." << endl;
    swap(m, m.getFront(), m.getFront()->next);
    printList(m);

    cout << "Swapping second and first elements..." << endl;
    swap(m, m.getFront()->next, m.getFront());
    printList(m);


    cout << endl << endl;
    cout << "Sorting..." << endl;
    printList(m);
    sortList(m);

    cout << "Sorted..." << endl;
    printList(m);


    return 0;
}


/// @brief find the node that precedes the provided node in the linked list
/// @param m the linked list
/// @param c the node to search for the previous of
/// @return the pointer to the node prior to the one searched for
Node* findPrev(const List &m, Node *c)
{
    // Start search at front of the linked list
    Node *prev = m.getFront();

    // Empty list or bad search value, nothing to search
    if (prev == nullptr || c == nullptr)
    {
        return nullptr;
    }

    // Use linear search to traverse the linked list
    // to track the pointer to the previous node
    while(nullptr != prev && prev->next != c)
    {
        prev = prev->next;
    }

    // return the discovered node, nothing discovered will return
    // the nullptr from the end of a proper linked list
    return prev;
}

/// @brief swap two nodes of a linked list
/// @param m the list where swapping will occur
/// @param a pointer to node one to swap
/// @param b pointer to node two to swap
void swap(List &m, Node* a, Node *b)
{
    // invalid swap if either a or b is invalid
    // no swap when a and b are the same

    // acquire the previous values for swapping
    Node *aPrev = findPrev(m, a);
    Node *bPrev = findPrev(m, b);

    // swap the nodes by linking to previous nodes
    // checking whether each is the front of the linked list
    if (aPrev == nullptr)
    {
        m.setFront(b);
    }
    else
    {
        aPrev->next = b;
    }

    if (bPrev == nullptr)
    {
        m.setFront(a);
    }
    else
    {
        bPrev->next = a;
    }

    // swap the next pointers of the nodes
    Node *afterA = a->next;
    a->next = b->next;
    b->next = afterA;
}

/// @brief Find the first node with the minimum data using the 
///        provided node as the starting location for the search
/// @param start the first node to consider within the linked list
/// @return the pointer to the first node that contains the minimum data value
Node* findMin(Node *start)
{
    // with any pointer based algorithm, you should consider the 
    // nullptr case and whether you need to handle it as a special
    // case or whether other code covers it
    // for this implementation, our loop covers the case as we do
    // not dereference the pointer until inside the loop and the 
    // loop body will not execute if we are sent a nullptr
    // if (nullptr == start)
    // {
    //     return nullptr;
    // }

    // The min or max algorithm says we should initialize
    // to the first item or item's value in our search space
    Node *min = start;

    // Traverse the linked list starting at the provided node
    // We could use a while loop to traverse, similar to what
    // we have seen in other examples, but this is just a quick
    // example of how we would use a for loop for iterative
    // linked strutcure traversals.
    for(Node *cur = start; cur != nullptr; cur = cur->next)
    {
        // when what we are currently looking at 
        // is less than what we have tracked as our minimum
        // then we need to update our tracking variable
        if (cur->data < min->data)
        {
            min = cur;
        }
    }

    // return the discovered minimum node
    return min;
}

/// @brief sort the Linked List using selection sort algorithm
/// @param m the Linked List to sort
void selectionSort(List &m)
{
    // Iterate over every item in the Linked List
    for(Node *cur = m.getFront(); cur != nullptr; cur = cur->next)
    {
        // Determine the minimum value starting at current node
        Node *min = findMin(cur);

        // Swap the minimum value into the current spot
        swap(m, cur, min);

        // Nodes switched spots so the minimum is the new current
        cur = min;
        printList(m);
    }
}

/// @brief sort the Linked List using insertion sort algorithm
/// @param m the Linked List to sort
void insertionSort(List &m)
{
    Node* prev = nullptr;
    for(Node *cur = m.getFront(); cur != nullptr; cur = cur->next)
    {
        // iterate backwards swapping until final spot
        for(Node *walk = prev; walk != nullptr; walk = findPrev(m, walk))
        {
            // are we done swapping this value?
            if (walk->next != nullptr && walk->data <= walk->next->data)
            {
                break;
            }

            // store the next because it will take the spot of walking pointer
            Node *walkReset = walk->next;

            // swap the adjacent nodes
            swap(m, walk, walk->next);

            // reset so that we are back on "current" node
            walk = walkReset;
            printList(m);
        }

        // track the previous node for the internal loop
        prev = cur;
    }
}


/// @brief perform sort algorithm on Linked List
/// @param m the Linked List to sort
void sortList(List &m)
{
    // insertionSort(m);
    selectionSort(m);
}


/// @brief build a linked list of N nodes of random integers
/// @param m the list to put nodes into
/// @param n the quantity of nodes to add
void buildList(List &m, size_t n)
{
    Node* cur = m.getFront();
    Node* prev = nullptr;
    
    // keep adding until proper size achieved
    while (m.size() < n)
    {
        // set up the new node
        cur = new Node();
        
        // If we want to set to a default value we can 
        // use {} startin in C++11
        // cur->data = {};

        // Use pseudorandom number for data
        cur->data = rand() % 900 + 100;
        cur->next = nullptr;

        // add node into the list
        if(prev == nullptr)
        {
            m.setFront(cur);
        }
        else
        {
            prev->next = cur;
        }
        m.incrementSize();

        // move down the list, to place next item
        prev = cur;
        cur = cur->next;
    }
}

/// @brief print out the linked list to the console
/// @param m the linked list to print
void printList(const List &m)
{
    // traverse the linked list starting with the first node
    Node *cur = m.getFront();
    while (cur != nullptr)
    {
        cout << cur->data;

        // if another node exists, output a link
        if (cur->next != nullptr)
        {
            cout << " --> ";
        }

        cur = cur->next;
    }
    cout << endl;
}


// ----------------------------------------------------
// ------------ List Class Implementations ------------
// ----------------------------------------------------

/// @brief get the pointer to the front of the Linked List
/// @return private data member that is the pointer to the front of the list
Node* List::getFront() const
{
    return front;
}

/// @brief set the pointer to the front of the Linked List
/// @param c the pointer to a node to set front pointer to
void List::setFront(Node *c) 
{
    front = c;
}

/// @brief increase Linked List internal size by one
void List::incrementSize()
{
    sz++;
}

/// @brief return the quantity of nodes in the Linked List
/// @return the private data member for the size of the Linked List
size_t List::size() const
{
    return sz;
}

/// @brief create an empty list
List::List()
{
    front = nullptr;
    sz = {};
}




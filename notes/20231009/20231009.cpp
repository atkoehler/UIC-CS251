/// @file 20231009.cpp
/// @author Adam T Koehler, PhD
/// @date October 9, 2023
/// @brief Class code and notes from the lecture. This code utilizes
///         a linked list class to build towards linked list insertion sort.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include <iostream>
#include <random>

using namespace std;


struct Node
{
    int data;
    Node* next;
};

// General Linked List class with basic necessities
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


// helper function prototypes
void buildList(List &, size_t);
void printList(const List &);
Node* findPrev(const List &, Node *);
void swap(List &, Node*, Node*);
void sortList(List &);

int main()
{
    srand(0);
    const int N = 5;
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

    //swap the next pointers
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
        cur->data = rand() % 80 + 10;
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

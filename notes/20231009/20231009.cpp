/// @file 20231009.cpp
/// @author Adam T Koehler, PhD
/// @date October 9, 2023
/// @brief Class code and notes from the lecture. This code utilizes
///         a linked list class to build towards linked list inertion sort.

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


Node* findPrev(const List &m, Node *c)
{
    Node *prev = m.getFront();

    if (nullptr == prev)
    {
        return nullptr;
    }

    while(nullptr != prev && prev->next != c)
    {
        prev = prev->next;
    }

    return prev;
}


void buildList(List &m, size_t n)
{
    Node* cur = m.getFront();
    Node* prev = nullptr;
    
    while (m.size() < n)
    {
        // set up the new node
        cur = new Node();
        
        // If we want to set to a default value we can 
        // use {} startin in C++11
        // cur->data = {};
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

        // move down the list
        prev = cur;
        cur = cur->next;
    }
}

void printList(const List &m)
{
    Node *cur = m.getFront();
    while (cur != nullptr)
    {
        cout << cur->data;

        if (cur->next != nullptr)
        {
            cout << " --> ";
        }

        cur = cur->next;
    }
    cout << endl;
}


void swap(List &m, Node* a, Node *b)
{
    // acquire the previous values for swapping
    Node *aPrev = findPrev(m, a);
    Node *bPrev = findPrev(m, b);

    // store the next values for easier swapping
    Node *aAfter = a->next;
    Node *bAfter = b->next;

    // nothing to do if they are the same
    
    // adjacent swap where a is before
    
    // adjacent swap where b is before
    
    // non-adjacent swap    

        // is a the head of the list?

        // is b the head of the list?
}


// List class implementations
Node* List::getFront() const
{
    return front;
}

void List::setFront(Node *c) 
{
    front = c;
}

void List::incrementSize()
{
    sz++;
}

size_t List::size() const
{
    return sz;
}

List::List()
{
    front = nullptr;
    sz = {};
}
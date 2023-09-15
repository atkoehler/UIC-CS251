/// @file 20230915.cpp
/// @author Adam T Koehler, PhD
/// @date September 15, 2023
/// @brief Class code and notes from the lecture. This code utilizes
///         a myQ class to introduce class concepts and test. The class is
///         a queue data structure built with two C++ stacks 
///         as the underlying implementation.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include <iostream>
#include <stack>

using namespace std;

// Class declaration for our queue implementation
class myQ
{
    private:
        stack<int> stack1, stack2;
    public:
        void pop();
        void push(int);
        int front();
        bool empty() const;
        size_t size() const;  
    private:
        void transfer(); 
};

/// @brief transfer all items from stack1 to stack2, reversing stack1 order
/// @post stack1 will be empty, stack2 will contain all the queue values
void myQ::transfer()
{
    while (!stack1.empty()) 
    {
        stack2.push(stack1.top());
        stack1.pop();
    }    
}

/// @brief acquire the value of the front-most element in the queue
/// @return the integer value of the front-most queue element
int myQ::front()
{
    // Nothing in stack2, move stack1 over
    if (stack2.empty()) 
    {
        // Reverse order by transfering
        transfer();
    }
    
    // We could build in error handling
    // if(stack2.empty())
    // {
    //     // calling top() on empty C++ queues is undefined behavior
    // }

    return stack2.top();
}

/// @brief remove front-most element from the queue
void myQ::pop()
{
    // Nothing in stack2, move stack 1 over
    if (stack2.empty()) 
    {
        // Reverse order by transfering
        transfer();
    }

    // We could build in error handling
    // if(stack2.empty())
    // {
    //     // calling pop() on empty C++ queues is undefined behavior
    // }

    // Pop the top item from internal stack2
    stack2.pop();
}

/// @brief place a new element at the back of the queue
/// @param value the integer value of the element to be placed into the queue
void myQ::push(int value)
{
    stack1.push(value);
}

/// @brief how many elements are in the queue
/// @return the quantity of the elements in the queue
size_t myQ::size() const
{
    return stack1.size() + stack2.size();
}

/// @brief determine if the queue is empty
/// @return true if the queue is empty, otherwise false
bool myQ::empty() const
{
    return stack1.empty() && stack2.empty();
}

// prototypes for functionality tests
bool top_SingleItemCheck();

int main()
{
    // Create a queue object
    myQ q;

    // output the size of the queue object
    cout << "Current Queue Size: " << q.size() << endl;

    // add a few things to the queue object
    q.push(2);
    q.push(7);
    q.push(5);

    // output the size of the queue object
    cout << "Current Queue Size: " << q.size() << endl;

    // remove a few things from the queue
    q.pop();
    q.pop();

    // output the size of the queue object
    cout << "Current Queue Size: " << q.size() << endl;

    // What happens when we pop more than we pushed?
    // q.pop();
    // q.pop();    
    // cout << q.size();
    // // cout << q.size() << endl;
    // cout << q.front() << endl;

    // Let's talk about testing.
    // Does our queue properly allow adding of one item?
   
    return 0;
}


/// @brief tests whether front() works for single item push() into queue
/// @return true if all tests are passed, otherwise false
/// @pre requires the following functions to work: size, push
bool top_SingleItemCheck()
{
    // Basic testing predicate function setup:
    // 1) Perform individual checks return false immediately upon failure.
    // 2) Making it through all the tests means success, return true.    

    return true;
}



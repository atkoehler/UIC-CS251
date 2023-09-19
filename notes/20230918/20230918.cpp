/// @file 20230918.cpp
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



/* ------------------------------------------------------------------- */
/* --------------------- CLASS DEFINITIONS BEGIN --------------------- */
/* ------------------------------------------------------------------- */

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



/* ------------------------------------------------------------------- */
/* ----------------------- MAIN PROGRAM BEGINS ----------------------- */
/* ------------------------------------------------------------------- */

// prototypes for functionality tests
void runTests();
bool front_SingleItemCheck();

// program execution
void executeProgram();

int main()
{
    // Execute the normal program sequence
    executeProgram();


    // Let's talk about testing.
    // Does our queue properly allow adding of one item?

    // We can define a single function to run all of our tests.
    // This allows us to comment or uncomment a single line in main
    // to either run the tests or execute the program.
    runTests();

    return 0;
}

/// @brief execute all the tests that have been developed
void runTests()
{
    front_SingleItemCheck();
}

/// @brief execute the normal program
void executeProgram()
{
    // Create a queue object
    myQ q;

    // output the size of the queue object
    cout << "Current Queue Size: " << q.size() << endl;

    // add a few things to the queue object
    q.push(3);
    q.push(2);
    q.push(7);

    // output the size of the queue object
    cout << "Current Queue Size: " << q.size() << endl;

    // remove a few things from the queue
    q.pop();

    // output the size of the queue object
    cout << "Current Queue Size: " << q.size() << endl;

    // What happens when we pop more than we pushed?
    // A: We should get an invalid size value with the above
    //      after popping too many times.
    // q.pop();
    // q.pop();
    // q.pop();
    // cout << "Current Queue Size: " << q.size() << endl;
    

    // What happens when we push something on after popping too much?
    // A: Our size is back to 0! That doesn't seem correct.
    // q.pop();
    // q.pop();
    // q.pop();
    // q.push(3);
    // cout << "Current Queue Size: " << q.size() << endl;
    

    // What happens when we attempt to get the front-most value
    // of the queue when we have popped too many times?
    // A: A segmentation fault may occor or we may just see
    //      some spurious output.
    // cout << q.front() << endl;

}

/// @brief tests whether front() works for single item push() into queue
/// @return true if all tests are passed, otherwise false
/// @pre requires the following functions to work: size, push
bool front_SingleItemCheck()
{
    // Basic testing predicate function setup:
    // 1) Perform individual checks return false immediately upon failure.
    // 2) Making it through all the tests means success, return true.  

    // Create a myQ object  
    myQ q;

    // Sanity check for size to make sure queue is properly created
    // This check should exist in a prior test case that checks size()
    if (0 != q.size())
    {
        cout << "ERROR: Invalid queue size after myQ construction."
            << endl << "\tExpected: 0" << "\tFound: " << q.size()
            << endl;
        return false;        
    }

    // Push a single value on to the queue
    int value = 3;
    q.push(value);

    // Sanity check for size to make sure push increased size()
    // This check should exist in a prior test case that checks push()
    if (1 != q.size())
    {
        cout << "ERROR: Invalid queue size after a single push."
            << endl << "\tExpected: 1" << "\tFound: " << q.size()
            << endl;
        return false;
    }

    // check the value at the front of the queue after the push
    int result = q.front();
    if (result != value)
    {
        cout << "ERROR: Invalid queue front value after a single push."
            << endl << "\tExpected: " << value << "\tFound: " << result
            << endl;
        return false;
    }

    // Test several values, using scope resolution to continually create
    // empty queues and only push a single item
    for(int i = 0; i < 100; ++i)
    {
        myQ x;
        x.push(i);
    
        // Test the actual value at the front of the queue
        int result = x.front();
        if (result != i)
        {
            cout << "ERROR: Invalid queue front value after a single push."
                << endl << "\tExpected: " << i << "\tFound: " << result
                << endl;
            return false;
        }        
    }

    return true;
}




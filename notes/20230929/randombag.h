/// @file randombag.h
/// @author Adam T Koehler, PhD
/// @date September 29, 2023
/// @brief Basic data structure implementation example using a random bag

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#pragma once


// ---------------------------------------------
// -------- BEGIN RANDOM BAG DEFINITION --------
// ---------------------------------------------
#include <vector> // underlying implementation

class RandomBag
{
    private:
        std::vector<int> elements;

    // here for demonstration as we do not need this area
    // protected: 

    public:
        void add(int);
        int removeRandom();
        bool isEmpty() const;
        int size() const;
};



// ----------------------------------------------
// ------ BEGIN RANDOM BAG IMPLEMENTATIONS ------
// ----------------------------------------------

#include <random>
#include <iostream> // for exception output to cerr


/// @brief how many elements exist in the random bag
/// @return the integer representation of the quantity of elements in the bag
int RandomBag::size() const
{
    return elements.size();
}

/// @brief is the bag empty?
/// @return true when the bag is empty, otherwise false
bool RandomBag::isEmpty() const
{
    return size() == 0;
}

/// @brief insert a item with the provided value into the bag
/// @param n the value to be inserted into the bag
void RandomBag::add(int n)
{
    elements.push_back(n);
}

/// @brief remove a random element from the bag
/// @return the value of the element pulled from the bag
int RandomBag::removeRandom()
{
    // output an error when attempting to
    // pull from an empty bag!
    if(isEmpty())
    {
        std::cerr << "EEEK!" << std::endl;
        return -1;
    }

    // determine a random element index and grab value
    int r = rand() % size();
    int val = elements.at(r);

    // erase the element from the vector
    elements.erase(elements.begin()+r);

    return val;
}

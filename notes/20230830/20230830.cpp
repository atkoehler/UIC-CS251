/// @file 20230830.cpp
/// @author Adam T Koehler, PhD
/// @date August 30, 2023
/// @brief Class code and notes from the lecture. This code emphasizes
///         moving from strings to vectors and file io.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int useStrings(const vector<string> &, const string &);
int useInts(const vector<int> &, int);
int useStringsR(const vector<string> &, const string &);
int useIntsR(const vector<int> &, int);
int compare(const auto &v, const auto & c);

// A simple main that executes the various functions
int main()
{
    vector<string> v1 = {"1", "2", "3", "4", "5", "6"};
    vector<int> v2 = {1, 2, 3, 4, 5, 6};

    // We want to perform the function call 10,000,000 times
    // to help simulate large scale amount of operations
    // when we only use smaller vectors.
    int N = 100000000;
    int count = 0;

    // Uncommenting one funtion call at a time and recompiling will allow
    // timed execution of that specific function using "time ./a.out"
    // or similar terminal timing program. This is a quick-and-dirty way
    // to demonstrate the timing differences of using strings versus ints
    // and reference variables and not.
    for (int i = 0; i < N; ++i)
    {        
        // using normal variable in for-each loop
        // count += useStrings(v1, "3");
        // count += useInts(v2, 3);

        // using reference variable in for-each loop
        // count += useStringsR(v1, "3");
        // count += useIntsR(v2, 3);

        // using generalized function in two different ways
        // count += compare(v1, "3");  // with string vector
        // count += compare(v2, 3);    // with integer vector
    }
    cout << count << endl;
}


// @brief example of using auto to generalize a function
//        which iterates over a container and counts how many times 
//        a specific element is seen
// @param v the container (vector) to iterate over
// @param c the comparison value to count quanity of 
// @return the quantity of matches to the comparison value
int compare(const auto &v, const auto &c)
{
    int count = 0;

    // for every element in the container v
    for (const auto &element : v)
    {
        if (c == element)
        {
            count++;
        }
    }

    return count;
}


// @brief count how many of a specific string exist in a vector
// @param v the vector of strings to iterate over
// @param c the comparison value to count quanity of 
// @return the quantity of matches to the comparison value
int useStrings(const vector<string> &v, const string &c)
{
    int count = 0;

    // a normal variable means a copy of the value is placed in element
    for (auto element : v)
    {
        if (c == element)
        {
            count++;
        }
    }

    return count;
}


// @brief count how many of a specific integer exist in a vector
// @param v the vector of integers to iterate over
// @param c the comparison value to count quanity of 
// @return the quantity of matches to the comparison value
int useInts(const vector<int> &v, int c)
{
    int count = 0;

    // a normal variable means a copy of the value is placed in element
    for (auto element : v)
    {
        if (c == element)
        {
            count++;
        }
    }

    return count;
}

// @brief count how many of a specific string exist in a vector
//        use a reference variable in the for-each loop
// @param v the vector of strings to iterate over
// @param c the comparison value to count quanity of 
// @return the quantity of matches to the comparison value
int useStringsR(const vector<string> &v, const string &c)
{
    int count = 0;

    // a reference variable allows us to modify the actual container values
    for (const auto &element : v)
    {
        if (c == element)
        {
            count++;
        }
    }

    return count;
}


// @brief count how many of a specific string exist in a vector
//        use a reference variable in the for-each loop
// @param v the vector of integers to iterate over
// @param c the comparison value to count quanity of 
// @return the quantity of matches to the comparison value
int useIntsR(const vector<int> &v, int c)
{
    int count = 0;
    
    // a reference variable allows us to modify the actual container values
    for (const auto &element : v)
    {
        if (c == element)
        {
            count++;
        }
    }

    return count;
}
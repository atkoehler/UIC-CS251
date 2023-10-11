/// @file tests.cpp
/// @author Adam T Koehler, PhD
/// @date October 10, 2023
/// @brief Provided testing file to implement Catch 1.x framework tests. 
///   The example below uses the Catch testing framework version that uses
///   a single .hpp file. Initial file authored by:
///   Adam T Koehler, PhD - University of Illinois Chicago

// The tutorial for Catch 1.x can be found at:
// https://github.com/catchorg/Catch2/blob/Catch1.x/docs/tutorial.md
//
// Example of building a Linked List without a class or loops:
// https://docs.google.com/presentation/d/1_0bSlsyprw9JsGaylCeU3W2me7HVNocFJkXWfkoyEPw/preview

// This tells Catch to provide a main() - do not remove
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

using namespace std;

// Items needed for building a list
struct Node
{
    int data;
    Node *next;
};

// externally defined function that is being tested
extern bool isSorted(Node *);


// #####################################
// TEST CASE 0 - isSorted() - nothing
// Requires: 
// #####################################
TEST_CASE("No Tests") 
{
    REQUIRE(true == true);
}



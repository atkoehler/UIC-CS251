/// @file ctests.cpp
/// @author Adam T Koehler, PhD
/// @date September 29, 2023
/// @brief Basic testing of the random bag data structure using the Catch Framework v1.0

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

// This tells Catch to provide a main() function
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "randombag.h"

// #####################################
// TEST CASE 0 - Example Empty Test
// Requires: Nothing
// #####################################
TEST_CASE("(0) no tests") 
{
  //
  // done
  //
}


// #####################################
// TEST CASE 1 - Check empty bag construction
// Requires: size()
// #####################################
TEST_CASE("randombag constructor") {
    RandomBag r;

    // a new bag should be size 0 when set up properly
    REQUIRE(r.size() == 0);
}


// #####################################
// TEST CASE 2 - add() multiple items
// Requires: size()
// #####################################
TEST_CASE("randombag add") {
    RandomBag r;
    for(int i=1; i < 10; ++i)
    {
        r.add(i);

        // validate size grew to expected size
        REQUIRE(r.size() == i);
    }
}


// #####################################
// TEST CASE 3 - isEmpty
// Requires: add()
// #####################################
TEST_CASE("randombag isEmpty") {
    RandomBag r;
    REQUIRE(r.isEmpty() == true);
    r.add(-123);
    REQUIRE(r.isEmpty() == false);
}


// #####################################
// TEST CASE 4 - removeRandom
// Requires: add(), isEmpty()
// #####################################
TEST_CASE("randombag removeRandom") {
    RandomBag r;
    int counter1 = 0, counter2 = 0;

    // Add a bunch of values to the bag
    for(int i=1; i <= 10; ++i)
    {
        // limit the values to certain values
        r.add(i % 3);
        counter1++;
    }

    // remove everything from the bag
    while(!r.isEmpty())
    {
        int x = r.removeRandom();

        // verify that the item removed is
        // one of the potential values
        bool checker = x == 0 || x == 1 || x == 2;
        REQUIRE(checker == true);
        counter2++;
    }

    // validate that the number of things
    // going into the bag and coming out are the same
    REQUIRE(counter1 == counter2);
}

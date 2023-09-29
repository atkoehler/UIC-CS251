/// @file gtests.cpp
/// @author Adam T Koehler, PhD
/// @date September 29, 2023
/// @brief Basic testing of the random bag data structure using the Google Test (gtest) Framework

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).




#include "randombag.h"
#include <gtest/gtest.h>

// #####################################
// TEST CASE 0 - Example Empty Test
// Requires: Nothing
// #####################################
TEST(randombag, noTest)
{
  //
  // done
  //
}


// #####################################
// TEST CASE 1 - Check empty bag construction
// Requires: size()
// #####################################
TEST(randombag, constructor) {
    RandomBag r;

    // a new bag should be size 0 when set up properly
    EXPECT_EQ(r.size(), 0);
}


// #####################################
// TEST CASE 2 - add() multiple items
// Requires: size()
// #####################################
TEST(randombag, add) {
    RandomBag r;
    for(int i=1; i < 10; ++i)
    {
        r.add(i);

        // validate size grew to expected size
        EXPECT_EQ(r.size(), i);
    }
}


// #####################################
// TEST CASE 3 - isEmpty before and after an add
// Requires: add()
// #####################################
TEST(randombag, isEmpty) {
    RandomBag r;
    EXPECT_EQ(r.isEmpty(), true);
    r.add(-123);
    EXPECT_EQ(r.isEmpty(), false);
}



// #####################################
// TEST CASE 4 - removeRandom
// Requires: add(), size()
// #####################################
TEST(randombag, removeRandom)
{
    RandomBag r;
    int counter1 = 0, counter2 = 0;

    // Add a bunch of values to the bag
    for(int i = 1; i <= 10; ++i)
    {
        // limit the values to certain values
        r.add(i % 3);
        counter1++;
    }

    // remove items from the bag
    while(r.size() != 0)
    {
        int curSize = r.size();
        int x = r.removeRandom();

        // make sure the size is decreased by 1
        EXPECT_EQ(r.size(), curSize - 1);

        // make sure that the value extracted
        // from the bag is one of the potential 
        // values we inserted
        bool checker = x == 0 || x == 1 || x == 2;
        EXPECT_EQ(checker, true);

        counter2++;
    }

    // validate that the number of things
    // going into the bag and coming out of the
    // bag are the same
    EXPECT_EQ(counter1, counter2);
}
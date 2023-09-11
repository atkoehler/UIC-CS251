/// @file 20230911.cpp
/// @author Adam T Koehler, PhD
/// @date September 11, 2023
/// @brief Class code and notes from the lecture. This code emphasizes
///         C++ sets and maps and interactions with those containers.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    set<string> s;
    map<string, int> m;

    string word;
    int value;
    
    // we can acquire two whitespace separated items at once
    while (cin >> word >> value)
    {
        // insert into the set container
        s.insert(word);

        // for the map there are many ways to insert:
        // we could use emplace which abstracts away the fact
        // maps take key-value pairs
        // m.emplace(word, value);

        // we could use insert, but maps contain pairs
        // so we would need to create a key-value pair
        // m.insert(pair<string,int>(word,value));

        // use the square bracket syntax
        m[word] = value;
    }


    // iterate over set or map containers and output
    cout << "Output the set contents: " << endl;
    for (string e : s)
    {
        cout << "word: " << e << endl;
    }
    cout << endl;

    cout << "Output the map contents without auto: " << endl;
    for (pair<string,int> e : m)
    {
        cout << "word: " << e.first << endl;
    }
    cout << endl;

    cout << "Output the map contents with const auto &: " << endl;
    for (const auto &e : m)
    {
        cout << "word: " << e.first << endl;
    }
    cout << endl;


    return 0;
}
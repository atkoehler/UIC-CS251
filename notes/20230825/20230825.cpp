/// @file 20230825.cpp
/// @author Adam T Koehler, PhD
/// @date August 25, 2023
/// @brief Class code and notes from the lecture. This code emphasizes
///         strings, input and output operators (insertion and extraction),
///         and stream interactions (console and file). Additionally
///         input redirection was demonstrated to show how to execute
///         a program without having to retype all the input.
///         ./a.out < filewithinputs.txt

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include <iostream> // for the console input and output streams
#include <string>   // for strings and string operations
#include <fstream>  // for file streams

using namespace std;

/// @brief build a string from console input stream, word by word
/// @return a string that was built using concatenation
string builder()
{
    string r, value;

    // extract chunks (in this case strings)
    // separated by whitespace using extraction
    // operator (>>) from the console input stream
    //
    // When >> gets to the end of file (EOF) it will 
    // put the stream into a fail state which causes
    // a false return value and exits the loop. To 
    // simulate this when typing inputs, instead of using
    // input redirection with a file, we can 
    // type ctrl+d to send the EOF character.
    while(cin >> value)
    {
        // generate a string using string 
        // concatenation placing the value
        // and a space into the string
        r += value + " ";
    }
    
    // due to always having a space (" ") with the value
    // the concatenated string will terminate with a single
    // space versus just end after the last character of
    // the last value.
    return r;
}


/// @brief build a string from a file stream, word by word
/// @return a string that was built using concatenation
string builder2()
{
    string r, value;

    // open the file when creating 
    // the input file stream
    ifstream inF("three.txt");

    // extract chunks (in this case strings)
    // separated by whitespace using extraction
    // operator (>>) from the file input stream
    while(inF >> value)
    {
        r += value + " ";
    }

    // it is always good practice to close
    // the file stream immediately when you
    // are done with the stream
    inF.close();
    
    return r;
}


/// @brief print out each element of the string separated by a space
/// @param s a constant reference string parameter to print out
void printer(const string &s)
{
    // const reference demonstrated here as the 
    // best method in most cases for passing a string

    // range base loops or for-each loops
    // are a version of for loops that 
    // perform an iteration for every element
    // within the container
    // for (char element : s)
    // {
    //     cout << element << ' ';
    // }
    // cout << endl;

    // auto is a keyword that will have the compiler
    // determine the type. The type still needs to work
    // with all the code that variable is used for as 
    // the variable is still that specific type.
    // Here auto translates to the character datatype (char)
    for (auto element : s)
    {
        cout << element << ' ';
    }
    cout << endl;
}

int main()
{
    // the function returns a string and that replaces
    // the function call and is then assigned into s
    string s = builder();

    // now use the file stream to build the string
    string s2 = builder2();

    // calling to print out every element of the string
    // each separated by a space.
    printer(s);
    printer(s2);

    return 0;
}
#!/bin/bash

#  @file executetests.sh
#  @author Adam T Koehler, PhD
#  @date October 10, 2023
#  @brief An executable script that compiles and executes Catch framework
#           tests to help assess test coverage based on executing all the 
#           tests on broken implementations.

#  Copyright Notice
#  This document is protected by U.S. copyright law. Reproduction and 
#  distribution of this work, including posting or sharing through any medium, 
#  is explicitly prohibited by law, and also violates UIC's Student 
#  Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
#  Participation in Academically Dishonest Activities: Material Distribution).


# set -x  # show execution flag

# define fancy colors and reset values
FAILED='\t\033[31;1m[NOT]\033[0m\n '
PASSED='\t\033[32;1m[COVERED]\033[0m\n '

correctP=0
correctF=0
pcount=0
fcount=0

SOLFILES=".solutions"
WORKING="working"

# create needed working files
mkdir "${WORKING}" >& /dev/null
cp tests.cpp "${WORKING}/tests.cpp" >& /dev/null
cp catch.hpp "${WORKING}/catch.hpp" >& /dev/null
echo -n "" "${WORKING}/indoutput.txt" >& /dev/null
echo -n "" "${WORKING}/output.txt" >& /dev/null
cd "${WORKING}" >& /dev/null

clear
echo "Compiling and executing tests..."

# attempt to compile the correct solution with the tests to check compilation
echo ""
echo -n "   basic compile check"
g++ -Wall -std=c++2a tests.cpp ../${SOLFILES}/func0.o -o tests.exe >& indoutput.txt 2>&1
value=$(wc -l < indoutput.txt)
if (( "$value" != 0 ))
then
    stdbuf -oL printf ${FAILED}
    echo ""
    echo "Compilation result:"
    cat indoutput.txt
    cd ..
    rm -rf ${WORKING}
    exit 1
else
    stdbuf -oL printf ${PASSED}
fi

# run and test correct solution
echo ""
echo -n "   correct solution 1"
echo "Executing on Function Implementation 0 - Correct Solution" > output.txt
echo -n "" > indoutput.txt

# short rest before attempting next command
sleep 2

./tests.exe > indoutput.txt 2>&1

# output colorized result to console based on finding "failed" 
value=$(wc -l < indoutput.txt)
if (( "$value" != 0 )); then
    cat indoutput.txt >> output.txt
    value=$(grep "failed" indoutput.txt | wc -l)
    if (( "$value" != 0 )); then
        stdbuf -oL printf ${FAILED}
        correctF=$((correctF+1))
    else
        stdbuf -oL printf ${PASSED}
        correctP=$((correctP+1))
    fi
else
    stdbuf -oL printf ${FAILED}
    correctF=$((correctF+1))
fi

# rest after testing, that was a lot of work
sleep 2

fileCounter=1
for filename in ../${SOLFILES}/*
do
    # skip the correct implementation file
    if [[ "$filename" = "../${SOLFILES}/func0.o" ]]
    then
        continue
    fi

    # attempt to compile and test possible incorrect solution
    echo ""
    echo -n "   incorrect solution ${fileCounter}"
    echo "" >> output.txt
    echo "Executing on Function Implementation ${fileCounter} - Incorrect Solution" >> output.txt
    echo -n "" > indoutput.txt
    g++ -Wall -std=c++2a tests.cpp "${filename#}" -o tests.exe
    while (( "$?" != 0 ))
    do
        g++ -Wall -std=c++2a tests.cpp "${filename#}" -o tests.exe
    done

    # short rest before attempting next command
    sleep 2
    
    ./tests.exe > indoutput.txt 2>&1

    # short rest before attempting next command
    sleep 2

    # output colorized result to console based on finding "failed" 
    value=$(wc -l < indoutput.txt)
    if (( "$value" != 0 )); then
        cat indoutput.txt >> output.txt
        value=$(grep "failed" indoutput.txt | wc -l)
        if ((  "$value" != 0 )); then
            stdbuf -oL printf ${PASSED}
            pcount=$((pcount+1))
        else
            stdbuf -oL printf ${FAILED}
            fcount=$((fcount+1))
        fi
    else
        stdbuf -oL printf ${FAILED}
        fcount=$((fcount+1))
    fi

    fileCounter=$((fileCounter+1))
done

# move the output file to permanent location
cp output.txt ../output.txt
cd ..

# clean up the working files
rm -rf ${WORKING}


# output notice on how to see full execution results
echo ""
echo "Overall coverage:"
echo -n "   Coverage for Correct Implementations - "
echo "${correctP} covered, ${correctF} not"
echo -n "   Coverage for Incorrect Implementations - "
echo "${pcount} covered, ${fcount} not"
echo ""
echo "See output.txt for full test output details."

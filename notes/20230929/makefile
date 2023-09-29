##################
# @file ctests.cpp
# @author Adam T Koehler, PhD
# @date September 29, 2023
# @brief Basic makefile to create Google Test or Catch v1.0 executables

# Copyright Notice
# This document is protected by U.S. copyright law. Reproduction and 
# distribution of this work, including posting or sharing through any medium, 
# is explicitly prohibited by law, and also violates UIC's Student 
# Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
# Participation in Academically Dishonest Activities: Material Distribution).
##############

# compile an executable with the Google Test Framework
# the compilation command includes several flags for Google Test Framework
# including the -lgtest_main flag telling it to create a main function
# to call all the the defined tests
gtest:
	g++ -std=c++20 -Wall gtests.cpp -o tests.exe -lgtest -lgtest_main -lpthread

# compile an executable with the Catch Framework v1.0
# we need less flags than gtest as using Catch v1.0 includes a 
# giant header file and a define statement to tell Catch to make a main
ctest:
	g++ -std=c++20 -Wall ctests.cpp -o tests.exe

# run the executable	
run:
	./tests.exe
	
# remove the executable
clean:
	rm -f ./tests.exe
##################
# @file makefile
# @author Adam T Koehler, PhD
# @date October 11, 2023
# @brief Basic makefile to work with the days live code notes
#
# Copyright Notice
# This document is protected by U.S. copyright law. Reproduction and 
# distribution of this work, including posting or sharing through any medium, 
# is explicitly prohibited by law, and also violates UIC's Student 
# Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
# Participation in Academically Dishonest Activities: Material Distribution).
##############

build:
	g++ -std=c++20 -Wall 20231011.cpp -o prog.out
	
run:
	./prog.out

clean:
	rm -f ./prog.out

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes  ./prog.out

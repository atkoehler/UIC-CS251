##################
# @file makefile
# @author Adam T Koehler, PhD
# @date October 2, 2023
# @brief Basic makefile to create Google Test or Catch v1.x executables
##################
solution:
	g++ -Wall -std=c++2a main.cpp canvaslist_solution.o shape_solution.o -o solution.exe

clean:
	rm -f solution.exe

runsolution:
	./solution.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./program.exe

build:
	g++ -std=c++20 -Wall 20231009.cpp -o prog.out
	
run:
	./prog.out

clean:
	rm -f ./prog.out

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./prog.out

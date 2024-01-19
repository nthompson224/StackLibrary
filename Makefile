# @file CMakeLists.txt
#
# CMake build for main

.PHONY: all

main: main.o Stack.o
	g++ -std=c++20 $^ -o $@

stack.o: Stack.cpp
	g++ -std=c++20 -c $<

main.o: main.cpp Stack.cpp
	g++ -std=c++20 -c $<

.PHONY: run
run: main
	./main

.PHONY: clean
clean : 
	@rm -f main.o Stack.o main
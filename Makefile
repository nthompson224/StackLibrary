# @file CMakeLists.txt
#
# CMake build for main

.PHONY: all

main: testStack.o Stack.o
	g++ -std=c++20 $^ -o $@

stack.o: Stack.cpp
	g++ -std=c++20 -c $<

testStack.o: testStack.cpp Stack.cpp
	g++ -std=c++20 -c $<

.PHONY: run
run: main
	./main

.PHONY: clean
clean : 
	@rm -f main.o Stack.o testStack.o main
# @file CMakeLists.txt
#
# CMake build for main

.PHONY: all

main_table: testStack.o Stack.o
	g++ -std=c++20 $^ -o $@


main_vector: testStackVector.o StackVector.o
	g++ -std=c++20 $^ -o $@

StackVector.o: StackVector.cpp
	g++ -std=c++20 $^ -c $@

stack.o: Stack.cpp
	g++ -std=c++20 -c $<

testStack.o: testStack.cpp Stack.cpp
	g++ -std=c++20 -c $<

testStackVector.o: testStackVector.cpp StackVector.cpp
	g++ -std=c++20 -c $<

.PHONY: run_table
run_table: main_table
	./main_table

.PHONY: run_vector
run_vector: main_vector
	./main_vector

.PHONY: clean
clean : 
	@rm -f *.o main_table main_vector
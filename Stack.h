/*
    Stack.h

    The header file for a stack.
*/

#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
    int size;
    int capacity;
    T* stackArr;

public:
    Stack(const int& size);
    ~Stack();

    void push(const T& item);
};

#include "Stack.cpp"
#endif

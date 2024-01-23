/*
    Stack.h

    The header file for a stack.
*/

#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
    int stackSize;
    int stackCapacity;
    T* stackArr;

public:
    Stack(const int& size);
    ~Stack();

    void push(const T& item);
    T pop();

    int size();
    int capacity();

    T& operator[](const int index) const;
};

#include "Stack.cpp"
#endif

/*
    StackVector.h

    The header file for a stack using a vector.
*/

#ifndef STACK_H
#define STACK_H

#include <vector>

template<typename T>
class StackVector {
    int stackSize;
    std::vector<T> stackVect;

public:
    StackVector();
    StackVector(const StackVector& stack);
    
    ~StackVector();

    void push(const T& item);
    T pop();

    int size();

    T& operator[](const int index) const;
};

#include "StackVector.cpp"
#endif

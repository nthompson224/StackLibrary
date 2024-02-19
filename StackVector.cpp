#ifndef STACK_CPP
#define STACK_CPP

#include "StackVector.hpp"

#include <iostream>

template<typename T>
StackVector<T>::StackVector() : stackSize(-1) {}

template<typename T>
StackVector<T>::StackVector(const StackVector& stack) : stackSize(stack.stackSize), stackVect(stack.stackVect) {}

template<typename T>
StackVector<T>::~StackVector() {}

template<typename T>
void StackVector<T>::push(const T& item) {
    stackVect.push_back(item);
    ++stackSize;
}

template<typename T>
T StackVector<T>::pop() {
    if (stackSize == -1) {
        throw "Stack is empty\n";
    }

    T element = stackVect[stackSize--];

    return element;
}

template<typename T>
int StackVector<T>::size() {
  return stackSize + 1;
}

template<typename T>
T& StackVector<T>::operator[](const int index) const {
    if (index > stackSize) {
        throw "Index out of range\n";
    }

    return stackVect[index];
}

#endif

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"

#include <iostream>

template<typename T>
Stack<T>::Stack(const int& arrSize) : stackCapacity(arrSize), stackSize(-1) {
    stackArr = new T[arrSize];
}

template<typename T>
Stack<T>::Stack(const Stack& stack) : stackSize(stack.stackSize), stackCapacity(stack.stackCapacity) {
    stackArr = new T[stack.stackCapacity];
    for (int i = 0; i <= stack.stackSize; ++i) {
        stackArr[i] = stack[i];
    }
}

template<typename T>
Stack<T>::~Stack() {
    delete[] stackArr;
}

template<typename T>
void Stack<T>::push(const T& item) {
    if (stackSize == stackCapacity || stackCapacity == 0) {
        throw "Stack is at capacity\n";
    }

    stackArr[++stackSize] = item;
}

template<typename T>
T Stack<T>::pop() {
    if (stackSize == -1) {
        throw "Stack is empty\n";
    }

    T element = stackArr[stackSize--];

    return element;
}

template<typename T>
int Stack<T>::size() {
  return stackSize;
}

template<typename T>
int Stack<T>::capacity() {
  return stackCapacity;
}

template<typename T>
T& Stack<T>::operator[](const int index) const {
    if (index > stackSize) {
        throw "Index out of range\n";
    }

    return stackArr[index];
}

#endif

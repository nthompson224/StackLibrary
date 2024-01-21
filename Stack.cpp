#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

#include <iostream>

template<typename T>
Stack<T>::Stack(const int& size) : capacity(size), size(0) {
    stackArr = new T[size];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] stackArr;
}

template<typename T>
void Stack<T>::push(const T& item) {
    if (size == capacity) {
        throw "Stack is at capacity";
    }

    stackArr[size] = item;
    ++size;
}

#endif

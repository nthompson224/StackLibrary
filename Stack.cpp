#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

#include <iostream>

template<typename T>
Stack<T>::Stack(const int& arrSize) : capacity(arrSize), size(-1) {
    stackArr = new T[arrSize];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] stackArr;
}

template<typename T>
void Stack<T>::push(const T& item) {
    if (size == capacity || capacity == 0) {
        throw "Stack is at capacity\n";
    }

    stackArr[++size] = item;
}

template<typename T>
T Stack<T>::pop() {
    if (size == -1) {
        throw "Stack is empty\n";
    }

    T element = stackArr[size--];

    return element;
}

template<typename T>
int Stack<T>::size() {
  return size;
}

template<typename T>
int Stack<T>::capacity() {
  return capacity;
}

template<typename T>
T& Stack<T>::operator[](const int index) const {
    if (index > size) {
        throw "Index out of range\n";
    }

    return stackArr[index];
}

#endif

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

#include <iostream>

template<typename T>
Stack<T>::Stack(const int& size) : size(size) {
    stackArr = new T[size];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] stackArr;
}

#endif
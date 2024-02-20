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
    /// @brief constructor
    /// @param [in] size the desired capacity for the stack
    Stack(const int& size);

    /// @brief Copy constructor
    /// @param [in] stack the stack to be copied from
    Stack(const Stack& stack);
    
    /// @brief deconstructor
    ~Stack();

    /// @brief push an item onto the stack
    /// @param [in] item the item to push
    void push(const T& item);

    /// @brief pop the item at the top of the stack
    /// @return the item at the top of the stack
    T pop();

    /// @brief get the current size of the stack
    /// @return the size of the stack
    int size();

    /// @brief get the capacity the stack can hold
    /// @return the capacity the stack can hold
    int capacity();

    /// @brief [] overload to index the stack indicies
    /// @param index the index of the stack to access
    /// @return the item from the stack at index
    T& operator[](const int index) const;
};

#include "Stack.cpp"
#endif

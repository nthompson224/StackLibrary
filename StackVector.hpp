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
    /// @brief constructor
    /// @param [in] size the desired capacity for the stack
    StackVector();

    /// @brief Copy constructor
    /// @param [in] stack the stack to be copied from
    StackVector(const StackVector& stack);
    
    /// @brief deconstructor
    ~StackVector();

    /// @brief push an item onto the stack
    /// @param [in] item the item to push
    void push(const T& item);

    /// @brief pop the item at the top of the stack
    /// @return the item at the top of the stack
    T pop();

    /// @brief get the current size of the stack
    /// @return the size of the stack
    int size();

    /// @brief [] overload to index the stack indicies
    /// @param index the index of the stack to access
    /// @return the item from the stack at index
    T& operator[](const int index) const;
};

#include "StackVector.cpp"
#endif

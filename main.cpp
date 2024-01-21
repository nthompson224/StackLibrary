#include "Stack.h"
#include <iostream>

int main() {

    Stack<int> stack(5);

    stack.push(5);

    std::cout << stack[0] << '\n';

    return 0;
}

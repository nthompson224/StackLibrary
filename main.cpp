#include "Stack.h"
#include <iostream>

int main() {
    try {
        Stack<int> stack(1);
        stack.push(2);
        auto element = stack.pop();
        std::cout << element;
    }
    catch (char const* e) {
        std::cout << e;
    }

    return 0;
}

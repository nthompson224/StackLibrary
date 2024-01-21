#include "Stack.h"
#include <iostream>
#include <cassert>

int main() {
    {
        char const* error = "";

        try {
            Stack<int> stack(0);
        }
        catch (char const* e) {
            error = e;
        }

        assert(error == "");
    }

    {
        char const* error = "";
        
        try {
            Stack<int> stack(0);
            stack.push(2);
        }
        catch (char const* e) {
            error = e;
        }

        assert(error == "Stack is at capacity\n");
    }

    {
        char const* error = "";
        
        try {
            Stack<int> stack(1);
            stack.push(2);
        }
        catch (char const* e) {
            error = e;
        }

        assert(error == "");
    }

    {
        char const* error = "";
        int data = 0;

        try {
            Stack<int> stack(1);
            stack.push(2);
            data = stack.pop();
        }
        catch (char const* e) {
            error = e;
        }

        assert(data == 2);
        assert(error == "");
    }
    

    return 0;
}

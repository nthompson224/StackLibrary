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
            Stack<int> stack(0);
            auto shouldThrowError = stack.pop();
        }
        catch (char const* e) {
            error = e;
        }

        assert(error == "Stack is empty\n");
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

    {
        char const* error = "";
        int data[2];

        try {
            Stack<int> stack(1);
            stack.push(2);
            stack.push(3);
            data[0] = stack.pop();
            data[1] = stack.pop();
        }
        catch (char const* e) {
            error = e;
        }

        assert(data[0] == 3);
        assert(data[1] == 2);
        assert(error == "");
    }

    {
        char const* error = "";
        int data[2];

        try {
            Stack<int> stack(1);
            stack.push(2);
            stack.push(3);
            data[0] = stack.pop();
            data[1] = stack.pop();
            auto shouldThrowError = stack.pop();
        }
        catch (char const* e) {
            error = e;
        }

        assert(data[0] == 3);
        assert(data[1] == 2);
        assert(error == "Stack is empty\n");
    }

    {
      char const* error = "";
      int capacity;
      int size;

      try {
        Stack<int> stack(5);
        capacity = stack.capacity();
        size = stack.size();
      }
      catch(char const* e) {
        error = e;
      }

      assert(capacity == 5);
      assert(size == -1);
      assert(error == "");
    }

    {
      char const* error = "";
      int capacity;
      int size;

      try {
        Stack<int> stack(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        capacity = stack.capacity();
        size = stack.size();
      }
      catch(char const* e) {
        error = e;
      }

      assert(capacity == 5);
      assert(size == 3);
      assert(error == "");
    }

    {
      char const* error = "";
      int data;
      int capacity;
      int size;

      try {
        Stack<int> stack(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        data = stack.pop();
        
        capacity = stack.capacity();
        size = stack.size();
      }
      catch(char const* e) {
        error = e;
      }

      assert(capacity == 5);
      assert(size == 2);
      assert(data == 4);
      assert(error == "");
    }
    
    std::cout << "All tests passed successfully!\n";

    return 0;
}

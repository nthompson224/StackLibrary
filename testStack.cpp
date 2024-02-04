#include "Stack.hpp"
#include <iostream>
#include <cassert>

char* convertToDigram(const std::string& strDigram) {
  char character1 = 0x20;
  char character2 = 0x20;

  if (isspace(strDigram[0]) || ispunct(strDigram[0])) {
    character1 = 0x20;
  }

  if (isspace(strDigram[1]) || ispunct(strDigram[1])) {
    character2 = 0x20;
  }

  if (isalpha(strDigram[0])) {
    character1 = strDigram[0];
  }

  if (isalpha(strDigram[1])) {
    character2 = strDigram[1];
  }

  char* digram = new char[2];
  digram[0] = character1;
  digram[1] = character2;

  return digram;
}

int main() {

  std::cout << "\nRUNNING TEST SCRIPTS\n\n";

  {
    std::cout << "Test Script 1\n\n";

    Stack<std::string> stack(2);

    std::string pop1;
    std::string pop2;
    std::string underflowError;

    const char* error;

    try {
      stack.push(convertToDigram("ab"));
      stack.push(convertToDigram("cd"));
      pop1 = stack.pop();
      pop2 = stack.pop();
      underflowError = stack.pop();

    }
    catch (char const* c) {
      error = c;
    }


    assert(stack.size() == 0);
    assert(stack.capacity() == 2);
    assert(pop1[0] == 'c');
    assert(pop1[1] == 'd');
    assert(pop2[0] == 'a');
    assert(pop2[1] == 'b');
    assert(error == "Stack is empty\n");

    std::cout << "stack.push(\"ab\")\n";
    std::cout << "stack.push(\"cd\")\n";
    std::cout << "stack.pop(): \"" << pop1[0] << pop1[1] << "\"\n";
    std::cout << "stack.pop(): \"" << pop2[0] << pop2[1] << "\"\n";
    std::cout << "stack.pop(): " << error << "\n";

    std::cout << "Test Script 1: Passed\n\n";
  }

  {
    std::cout << "Running Test Script 2\n\n";

    Stack<std::string> stack(4);

    std::string pop;
    const char* error;

    try {
      stack.push(convertToDigram("ab"));
      stack.push(convertToDigram("c"));
      pop = stack.pop();
      stack.push(convertToDigram("de"));
      stack.push(convertToDigram("f "));
      stack.push(convertToDigram("g."));
      stack.push(convertToDigram("hi"));
    }
    catch (char const* c) {
      error = c;
    }

    assert(stack.size() == 4);
    assert(stack.capacity() == 4);
    assert(pop[0] == 'c');
    assert(pop[1] == ' ');
    assert(error == "Stack is at capacity\n");

    std::cout << "stack.push(\"ab\")\n";
    std::cout << "stack.push(\"c\")\n";
    std::cout << "stack.pop(): \"" << pop[0] << pop[1] << "\"\n";
    std::cout << "stack.push(\"de\")\n";
    std::cout << "stack.push(\"f \")\n";
    std::cout << "stack.push(\"g.\")\n";
    std::cout << "stack.push(\"hi\"): " << error << "\n";

    std::cout << "Test Script 2: Passed\n\n";
  }

  return 0;
}

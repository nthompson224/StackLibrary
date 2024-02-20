#include "StackVector.hpp"
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

    StackVector<std::string> stackVector{};

    std::string pop1;
    std::string pop2;

    const char* error;

    try {
      stackVector.push(convertToDigram("ab"));
      stackVector.push(convertToDigram("cd"));
      pop1 = stackVector.pop();
      pop2 = stackVector.pop();
      auto underflowError = stackVector.pop();

    }
    catch (char const* c) {
      error = c;
    }


    assert(stackVector.size() == 0);
    assert(pop1[0] == 'c');
    assert(pop1[1] == 'd');
    assert(pop2[0] == 'a');
    assert(pop2[1] == 'b');
    assert(error == "Stack is empty\n");

    std::cout << "stackVector.push(\"ab\")\n";
    std::cout << "stackVector.push(\"cd\")\n";
    std::cout << "stackVector.pop(): \"" << pop1[0] << pop1[1] << "\"\n";
    std::cout << "stackVector.pop(): \"" << pop2[0] << pop2[1] << "\"\n";
    std::cout << "stackVector.pop(): " << error << "\n";

    std::cout << "Test Script 1: Passed\n\n";
  }

  {
    std::cout << "Running Test Script 2\n\n";

    StackVector<std::string> stackVector{};

    std::string pop;
    const char* error;

    try {
      stackVector.push(convertToDigram("ab"));
      stackVector.push(convertToDigram("c"));
      pop = stackVector.pop();
      stackVector.push(convertToDigram("de"));
      stackVector.push(convertToDigram("f "));
      stackVector.push(convertToDigram("g."));
      stackVector.push(convertToDigram("hi"));
    }
    catch (char const* c) {
      error = c;
    }

    assert(stackVector.size() == 5);
    assert(pop[0] == 'c');
    assert(pop[1] == ' ');

    std::cout << "stackVector.push(\"ab\")\n";
    std::cout << "stackVector.push(\"c\")\n";
    std::cout << "stackVector.pop(): \"" << pop[0] << pop[1] << "\"\n";
    std::cout << "stackVector.push(\"de\")\n";
    std::cout << "stackVector.push(\"f \")\n";
    std::cout << "stackVector.push(\"g.\")\n";
    std::cout << "stackVector.push(\"hi\")\n\n";

    std::cout << "Test Script 2: Passed\n\n";
  }

  return 0;
}

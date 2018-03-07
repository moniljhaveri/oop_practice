#include <iostream>
#include "Stack.h"
int main()
{
    Stack<int> myStack = Stack<int>(5);
    std::cout << myStack.top() << std::endl;
    return 0;
}
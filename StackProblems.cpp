#include <iostream>
#include "Stack.h"
int main()
{
    Stack<int> myStack = Stack<int>(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    std::cout << myStack.top() << std::endl;
    return 0;
}
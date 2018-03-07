#ifndef STACK_H
#define STACK_H
#include <iostream>

template <class T>
class Stack
{
private:
  int size = 0;
  int ind = -1;
  T *arr;
  void enlargen();
  void reduce();

public:
  Stack();
  Stack(T data);
  ~Stack();
  void push(T data);
  void pop();
  T top();
};
#endif

#include <iostream>
#include "Stack.h"

template <class T>
Stack<T>::Stack()
{
    arr = new T[0];
}

template <class T>
Stack<T>::Stack(T data)
{
    size = 2;
    arr = new T[size];
    ind++;
    arr[ind] = data;
}

template <class T>
Stack<T>::~Stack()
{
}

template <class T>
void Stack<T>::push(T data)
{
    ind++;
    arr[ind] = data;
    if ((ind + 1) >= size)
    {
        size *= 2;
        enlargen();
    }
}

template <class T>
void Stack<T>::pop()
{
    if (ind < 0)
        return;
    ind--;
    if (ind < (size / 4))
    {
        size /= 4;
        reduce();
    }
}

template <class T>
T Stack<T>::top()
{
    return arr[ind];
}

template <class T>
void Stack<T>::enlargen()
{
    T *newArr = new T[size];
    for (int i = 0; i <= (size / 2); i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = NULL;
    arr = newArr;
}

template <class T>
void Stack<T>::reduce()
{
    T *newArr = new T[size];
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = NULL;
    arr = newArr;
}
template class Stack<int>;
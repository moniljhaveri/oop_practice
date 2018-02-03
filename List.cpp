#include "List.hpp"
#include <vector>
#include <iostream>

List::List()
{
    this->size = 0;
    this->capacity = 0;
    this->iterator = 0;
}

List::List(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->iterator = 0;
}

List::~List()
{
}

bool List::isEmpty()
{
    return (this->size == 0);
}

bool List::isFull()
{
    return (this->size >= this->capacity);
}

void List::insert(int data)
{
    if (this->size < this->capacity)
    {
        this->size++;
        this->data.push_back(data);
    }
}

void List::visit(void (*pf)(int &))
{
    for (int i = 0; i < size; i++)
    {
        (*pf)(this->data[i]);
    }
}

void List::display()
{
    for (auto n : this->data)
    {
        std::cout << n << std::endl;
    }
}
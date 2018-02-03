#ifndef LIST_HPP
#define LIST_HPP
#include <vector>

class List
{
  public:
    List();
    List(int capacity);
    ~List();
    bool isEmpty();
    bool isFull();
    void insert(int data);
    void visit(unsigned int position, int data);
    void display();

  private:
    int size;
    int capacity;
    int iterator = 0;
    std::vector<int> data;
};

#endif
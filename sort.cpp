#include "sort.hpp"
#include <vector>
#include <iostream>
template <class T>
Sort<T>::Sort(const std::vector<T> arr)
{
    this->arr = new std::vector<T>();
    for (auto i : arr)
    {
        this->arr->push_back(i);
    }
}
template <class T>
Sort<T>::Sort() {}

template <class T>
Sort<T>::~Sort()
{
    (*arr).clear();
    delete (this->arr);
}
template <class T>
std::ostream &operator<<(std::ostream &os, const Sort<T> &sort)
{
    for (auto i : (*sort.arr))
    {
        os << i << std::endl;
    }
    return os;
}

template <class T>
MergeSort<T>::MergeSort() : Sort<T>()
{
}

template <class T>
MergeSort<T>::MergeSort(const std::vector<T> arr) : Sort<T>(arr) {}

int main()
{
    std::vector<int> test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    Sort<int> d(test);
    std::cout << d;
    return 0;
}
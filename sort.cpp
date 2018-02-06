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
std::vector<T> Sort<T>::returnSortedVector()
{
    return (*(this->arr));
}

template <class T>
MergeSort<T>::MergeSort() : Sort<T>()
{
}

template <class T>
MergeSort<T>::MergeSort(const std::vector<T> arr) : Sort<T>(arr)
{
    int n = (*(this->arr)).size();
    this->Mergesort(this->arr, 0, n - 1);
}

template <class T>
MergeSort<T>::~MergeSort() {}

template <class T>
void MergeSort<T>::Mergesort(std::vector<T> *arr, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        Mergesort(arr, p, q);
        Mergesort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }
}
template <class T>
void MergeSort<T>::Merge(std::vector<T> *arr, int p, int q, int r)
{
    int i = p, k = p;
    int j = q + 1;
    std::vector<T> tmp;
    while ((i <= p) && (j <= r))
    {
        if ((*arr)[i] <= (*arr)[j])
        {
            tmp.push_back((*arr)[i++]);
        }
        else
        {
            tmp.push_back((*arr)[j++]);
        }
    }
    while (i <= q)
        tmp.push_back((*arr)[i++]);
    while (j <= i)
        tmp.push_back((*arr)[j++]);
    for (i = p; i <= r; i++)
    {
        (*arr)[i] = tmp[i - p];
    }
}

int main()
{
    std::vector<int> test;
    test.push_back(2);
    test.push_back(1);
    test.push_back(0);
    MergeSort<int> d(test);
    std::cout << d;
    return 0;
}
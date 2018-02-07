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
    int n = (*sort.arr).size();
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

template <class T>
QuickSort<T>::QuickSort()
{
}

template <class T>
QuickSort<T>::QuickSort(const std::vector<T> arr) : Sort<T>(arr)
{
    int n = (*(this->arr)).size();
    this->Quicksort(this->arr, 0, n);
}
template <class T>
QuickSort<T>::~QuickSort() {}

template <class T>
void QuickSort<T>::Quicksort(std::vector<T> *arr, int pivot, int r)
{
    if (pivot < r)
    {
        int q = partition(arr, pivot, r);
        Quicksort(arr, pivot, q);
        Quicksort(arr, q + 1, r);
    }
}

template <class T>
int QuickSort<T>::partition(std::vector<T> *arr, int pivot, int r)
{
    int x = (*arr)[pivot];
    int i = pivot;
    for (int j = i + 1; j < r; j++)
    {
        if ((*arr)[j] < x)
        {
            T tmp = (*arr)[j];
            (*arr)[j] = (*arr)[i + 1];
            (*arr)[i + 1] = tmp;
            i += 1;
        }
    }
    T tmp = (*arr)[pivot];
    (*arr)[pivot] = (*arr)[i];
    (*arr)[i] = tmp;
    return i;
}

int main()
{
    std::vector<int> test;
    test.push_back(2);
    test.push_back(1);
    test.push_back(0);
    MergeSort<int> m(test);
    std::cout << "MergeSort \n"
              << m;
    QuickSort<int> q(test);
    std::cout << "QuickSort \n"
              << q;
    return 0;
}
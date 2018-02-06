#ifndef SORT_HPP
#define SORT_HPP
#include <vector>
#include <iostream>
template <class T>
class Sort
{
public:
  Sort(const std::vector<T> arr);
  Sort();
  virtual ~Sort();
  std::vector<T> returnSortedVector();

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const Sort<U> &sort);

protected:
  std::vector<T> *arr;
};

template <class T>
class MergeSort : public Sort<T>
{
public:
  MergeSort(const std::vector<T> arr);
  MergeSort();
  ~MergeSort();

private:
  void Mergesort(std::vector<T> *arr, int p, int r);
  void Merge(std::vector<T> *arr, int p, int q, int r);
};
#endif
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

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const Sort<U> &sort);

private:
  std::vector<T> *arr;
};

template <class T>
class MergeSort : public Sort<T>
{
public:
  MergeSort(const std::vector<T> arr);
  MergeSort();
};
#endif
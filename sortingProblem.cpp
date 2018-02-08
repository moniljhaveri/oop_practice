#include <iostream>
#include <vector>
#include "sort.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>

void swap(int *i1, int *i2);
void quickSort(std::vector<int> *arr, int low, int high);
int partition(std::vector<int> *arr, int low, int high);

void quickSort(std::vector<int> *arr, int low, int high)
{
    if (low < high)
    {
        int q = partition(arr, low, high);
        quickSort(arr, low, q);
        quickSort(arr, q + 1, high);
    }
}
int partition(std::vector<int> *arr, int low, int high)
{
    int pivot = (*arr)[low];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if ((*arr)[j] < pivot)
        {
            swap(&(*arr)[j], &(*arr)[i + 1]);
            i++;
        }
    }
    swap(&(*arr)[low], &(*arr)[i]);
    return i;
}
void swap(int *i1, int *i2)
{
    int tmp = *i1;
    *i1 = *i2;
    *i2 = *i1;
}

int countUniqueElements(std::vector<int> vec)
{
    int uElements = 1;
    int elem = vec[0];
    for (auto i : vec)
    {
        if (i != elem)
        {
            elem = i;
            uElements++;
        }
    }
    return uElements;
}

int findWinner(std::vector<int> vec)
{
    int maxVoter = 0;
    int maxCount = 1;
    int uId = vec[0];
    int count = 1;
    for (auto i : vec)
    {
        if (uId != i)
        {
            count = 1;
            uId = i;
        }
        else
        {
            count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxVoter = i;
        }
    }
    return maxVoter;
}
void reverseString()
{
    std::string s = "Hello World!";
    char arr[s.size() + 1];
    std::strcpy(arr, s.c_str());
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        char tmp = arr[n - 1 - i];
        arr[n - 1 - i] = arr[i];
        arr[i] = tmp;
    }
    for (auto i : arr)
    {
        std::cout << i;
        ;
    }
    std::cout << std::endl;
}

int problem3()
{
    std::vector<int> testArr;
    testArr.push_back(4);
    testArr.push_back(4);
    testArr.push_back(4);
    testArr.push_back(4);
    testArr.push_back(4);
    testArr.push_back(4);
    testArr.push_back(3);
    testArr.push_back(3);
    testArr.push_back(3);
    testArr.push_back(3);
    testArr.push_back(2);
    testArr.push_back(1);
    testArr.push_back(0);
    testArr.push_back(0);
    testArr.push_back(0);
    testArr.push_back(1);
    testArr.push_back(1);
    testArr.push_back(1);
    testArr.push_back(1);
    //QuickSort<int> q(testArr);
    quickSort(&testArr, 0, testArr.size());
    int ans = findWinner(testArr);
    return ans;
}

int problem1()
{
    std::vector<int> testArr;
    testArr.push_back(4);
    testArr.push_back(3);
    testArr.push_back(3);
    testArr.push_back(3);
    testArr.push_back(3);
    testArr.push_back(2);
    testArr.push_back(1);
    testArr.push_back(0);
    testArr.push_back(0);
    testArr.push_back(0);
    testArr.push_back(1);
    testArr.push_back(1);
    testArr.push_back(1);
    testArr.push_back(1);
    QuickSort<int> q(testArr);
    testArr = q.returnSortedVector();
    int uC = countUniqueElements(testArr);
    return uC;
}

TEST_CASE("Sorting Problems", "[sorting]")
{
    reverseString();
    REQUIRE(problem1() == 5);
    REQUIRE(problem3() == 4);
}

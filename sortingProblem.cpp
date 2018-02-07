#include <iostream>
#include <vector>
#include "sort.hpp"

int countUniqueElements(std::vector<int> vec)
{
    int uElements = 0;
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

void problem1()
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
    if (uC != testArr.size())
    {
        std::cout << "Not unique" << std::endl;
    }
}

int main()
{
    problem1();
    return 0;
}
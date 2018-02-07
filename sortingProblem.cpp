#include <iostream>
#include <vector>
#include "sort.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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
    QuickSort<int> q(testArr);
    int ans = findWinner(q.returnSortedVector());
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
    REQUIRE(problem1() == 5);
    REQUIRE(problem3() == 4);
}

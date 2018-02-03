// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include "vect.h"
#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime>   // time() prototype
#include <fstream>
#include <vector>
int max(std::vector<int> x)
{
    int m = -1;
    for (auto i : x)
    {
        if (i > m)
        {
            m = i;
        }
    }
    return m;
}
int min(std::vector<int> x)
{
    int m = 2000000000;
    for (auto i : x)
    {
        if (i < m)
        {
            m = i;
        }
    }
    return m;
}
double average(std::vector<int> x)
{
    double n = 0.0;
    double sum = 0.0;
    for (auto i : x)
    {
        n += 1.0;
        sum += (double)i;
    }
    return sum / n;
}

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0)); // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int n;
    cout << "Enter number of trials";
    cin >> n;
    cout << "Enter target distance (q to quit): ";
    std::ofstream out;
    vector<int> stepAv;
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        for (int i = 0; i < n; i++)
        {
            result.reset(0.0, 0.0);
            steps = 0;

            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::Mode::POL);
                result = result + step;
                steps++;
                out << steps << ": " << result << std::endl;
            }
            stepAv.push_back(steps);
        }
        cout << "After n trials average " << average(stepAv) << std::endl;
        cout << "max " << max(stepAv) << std::endl;
        cout << "min " << min(stepAv) << std::endl;
    }
    cout << "Bye!\n";
    /* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0;
}

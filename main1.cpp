#include <iostream>
using namespace std;
#include "Complex.hpp" // to avoid confusion with complex.h
int main()
{
    Complex a(3.0, 4.0);
    // initialize to (3,4i)Programming Exercises
    Complex c(1.0, 1.0);
    std::cout << c << std::endl;
    std::cout << "addition " << c + a << std::endl;
    std::cout << "subtraction " << c - a << std::endl;
    std::cout << "multiplication 1 " << c * a << std::endl;
    std::cout << "multiplication 2 " << c * 3 << std::endl;
    std::cout << "conjugation " << ~c << std::endl;

    /*
    cout << "c is " << c << '\n';
    cout << "complex conjugate is " << ~c << '\n';
    cout << "a is " << a << '\n';
    cout << "a + c is " << a + c << '\n';
    cout << "a - c is " << a - c << '\n';
    cout << "a * c is " << a * c << '\n';
    cout << "2 * c is " << 2 * c << '\n';
    cout << "Done!\n";
    */
    return 0;
}
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>
class Complex
{
  public:
    Complex();
    Complex(double real, double image);
    ~Complex();
    Complex operator+(const Complex &b) const;
    Complex operator-(const Complex &b) const;
    Complex operator*(const Complex &b) const;
    Complex operator*(double d) const;
    Complex operator~() const;
    friend std::ostream &operator<<(std::ostream &os, const Complex &b);

  private:
    double real;
    double imag;
};
#endif
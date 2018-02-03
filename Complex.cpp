#include "Complex.hpp"
#include <iostream>

Complex::Complex() {}

Complex::Complex(double real, double imag)
{
    this->real = real;
    this->imag = imag;
}
Complex::~Complex() {}
Complex Complex::operator+(const Complex &b) const
{
    return Complex(real + b.real, imag + b.imag);
}

Complex Complex::operator-(const Complex &b) const
{
    return Complex(real - b.real, imag - b.imag);
}

std::ostream &operator<<(std::ostream &os, const Complex &b)
{
    os << b.real << " + " << b.imag << "i";
    return os;
}

Complex Complex::operator*(const Complex &b) const
{
    return Complex(real * b.real - imag * b.imag, imag + b.imag * real);
}

Complex Complex::operator*(double r) const
{
    return Complex(real * r, imag * r);
}
Complex Complex::operator~() const
{
    return Complex(real, -1 * imag);
}
/*

Complex Complex::operator*(const Complex &b) const
{
    return Complex(real * b.real - imag * b.imag, imag + b.imag * real);
}

Complex Complex::operator*(const double r) const
{
    return Complex(real * r, imag * r);
}

Complex Complex::operator~()
{
    return Complex(real, -1 * imag);
}
std::ostream &operaVtor << (std::ostream & os, const Complex &v)
{
    os << v.real << " + " << v.imag << "i";
    return os;
}
*/

// string1.cpp -- String class methods
#include <cstring>     // string.h for some
#include "string2.hpp" // includes <iostream>
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char *s) // construct String from C string
{
    len = std::strlen(s);    // set size
    str = new char[len + 1]; // allot storage
    std::strcpy(str, s);     // initialize pointer
    num_strings++;           // set object count
}

String::String() // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0'; // default string
    num_strings++;
}

String::String(const String &st)
{
    num_strings++;            // handle static member update
    len = st.len;             // same length
    str = new char[len + 1];  // allot space
    std::strcpy(str, st.str); // copy string to new location
}

String::~String() // necessary destructor
{
    --num_strings; // required
    delete[] str;  // required
}

// overloaded operator methods

// assign a String to a String
String &String::operator=(const String &st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

// assign a C string to a String
String &String::operator=(const char *s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

// read-write char access for non-const String
char &String::operator[](int i)
{
    return str[i];
}

// read-only char access for const String
const char &String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

String &String::operator+(const String &s)
{
    int newLen = s.length() + this->len + 1;
    char newArr[newLen + 1];
    std::strcpy(newArr, this->str);
    int n = this->len;
    for (int i = 0; i <= this->len; i++)
    {
        newArr[n + i] = s.str[i];
    }
    delete[] str;
    this->len = newLen;
    newArr[newLen - 1] = '\0';
    str = new char[0];
    std::strcpy(str, newArr);
    return *this;
}

void String::stringlow()
{
    for (int i = 0; i < this->len; i++)
    {
        if ((this->str[i] < 91) && (this->str[i] > 64))
        {
            this->str[i] += 32;
        }
    }
}

void String::stringup()
{
    for (int i = 0; i < this->len; i++)
    {
        if ((this->str[i] < 123) && (this->str[i] > 96))
        {
            this->str[i] -= 32;
        }
    }
}

int String::numchar(char c)
{
    int n = 0;
    for (int i = 0; i < this->len; i++)
    {
        if (c == this->str[i])
        {
            n++;
        }
    }
    return n;
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
istream &operator>>(istream &is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

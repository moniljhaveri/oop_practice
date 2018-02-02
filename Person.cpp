#include "Person.hpp"
#include <string>
#include <cstring>
#include <iostream>

Person::Person(const std::string &ln, const char *fn)
{
    this->lname = ln;
    strncpy(this->fname, fn, LIMIT);
    this->fname[LIMIT - 1] = '\0';
}

void Person::Show() const
{
    std::cout << "First Name " << this->fname << " Last Name " << this->lname << std::endl;
}
void Person::FormalShow() const
{
    std::cout << "Last Name " << this->lname << " First Name " << this->fname << std::endl;
}
#include "Cow.hpp"
#include <iostream>
#include <cstring>
#include <string.h>

Cow::Cow()
{
    this->weight = 0.0;
    this->name[0] = '\0';
    this->hobby = nullptr;
}
Cow::~Cow() {}

Cow::Cow(const char *nm, const char *ho, double wt)
{
    strncpy(this->name, nm, 20);
    int len = std::strlen(ho);
    this->hobby = new char[len];
    strcpy(this->hobby, ho);
    this->weight = wt;
}

Cow::Cow(const Cow &c)
{
    strncpy(this->name, c.name, 20);
    strcpy(this->hobby, c.hobby);
    this->weight = c.weight;
}

Cow &Cow::operator=(const Cow &c)
{
    strncpy(this->name, c.name, 20);
    int len = std::strlen(c.hobby);
    this->hobby = new char[len];
    strcpy(this->hobby, c.hobby);
    this->weight = c.weight;
    return (*this);
}

void Cow::ShowCow() const
{
    if (this->name[0] == '\0')
    {

        return;
    }
    std::cout << this->name << " " << this->hobby << " " << this->weight << std::endl;
    return;
}

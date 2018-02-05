#include "Classic.hpp"
#include <iostream>
#include <cstring>

Cd::Cd()
{
    this->performers[0] = '\0';
    this->label[0] = '\0';
    this->selections = 0;
    this->playtime = 0.0;
}
Cd::Cd(const Cd &d)
{
    std::strcpy(this->performers, d.performers);
    std::strcpy(this->label, d.label);
    this->selections = d.selections;
    this->playtime = d.playtime;
}
Cd::Cd(char *s1, char *s2, int n, double x)
{
    std::strcpy(this->performers, s1);
    std::strcpy(this->label, s2);
    this->selections = n;
    this->playtime = x;
}
Cd::~Cd() {}
void Cd::Report() const
{
    if (this->performers[0] == '\0')
        return;
    std::cout << this->performers << " " << this->label << " " << this->selections << " " << this->playtime << std::endl;
}

Cd &Cd::operator=(const Cd &d)
{

    std::strcpy(this->performers, d.performers);
    std::strcpy(this->label, d.label);
    this->selections = d.selections;
    this->playtime = d.playtime;
    return *this;
}

Classic::Classic(char *s1, char *s2, char *s3, int n, double x) : Cd(s1, s2, n, x)
{
    std::strcpy(this->primaryWork, s3);
}

Classic::Classic() : Cd()
{
    this->primaryWork[0] = '\0';
}

Classic::~Classic()
{
}
void Classic::Report() const
{
    Cd::Report();
    std::cout << this->primaryWork << std::endl;
}
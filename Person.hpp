#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>

class Person
{
  public:
    Person()
    {
        this->lname = " ";
        this->fname[0] = '\0';
    };
    Person(const std::string &ln, const char *fn = "Heyyou");
    ~Person(){};
    void Show() const;
    void FormalShow() const;

  private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
};
#endif
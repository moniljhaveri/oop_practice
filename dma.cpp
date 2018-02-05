// dma.cpp --dma class methods

#include "dma.h"
#include <cstring>

ABC::ABC(const char *l, int r)
{

    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}
ABC::ABC(const ABC &r)
{

    label = new char[std::strlen(r.label) + 1];
    std::strcpy(label, r.label);
    rating = r.rating;
}
ABC::ABC() {}
ABC::~ABC()
{
    delete[] label;
}
// baseDMA methods
baseDMA::baseDMA(const char *l, int r) : ABC(l, r)
{
}

baseDMA::baseDMA(const baseDMA &rs) : ABC(rs)
{
}

baseDMA::~baseDMA()
{
}

ABC &ABC::operator=(const ABC &rs)
{
    if (this == &rs)
        return *this;
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const ABC &rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char *c, const char *l, int r)
    : ABC(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char *c, const ABC &rs)
    : ABC(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &ls)
{
    os << (const baseDMA &)ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasDMA methods
hasDMA::hasDMA(const char *s, const char *l, int r)
    : ABC(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs)
    : ABC(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs)
    : ABC(hs) // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    ABC::operator=(hs); // copy base portion
    delete[] style;     // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const hasDMA &hs)
{
    os << (const baseDMA &)hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}

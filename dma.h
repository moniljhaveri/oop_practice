// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

//  Base Class Using DMA
class ABC
{
private:
  char *label;
  int rating;

public:
  ABC(const char *l = "null", int r = 0);
  ABC(const ABC &r);
  ABC();
  virtual ~ABC();
  friend std::ostream &operator<<(std::ostream &os,
                                  const ABC &rs);
  ABC &operator=(const ABC &rs);
};
class baseDMA : public ABC
{
private:
public:
  baseDMA(const char *l = "null", int r = 0);
  baseDMA(const baseDMA &rs);
  virtual ~baseDMA();
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public ABC
{
private:
  enum
  {
    COL_LEN = 40
  };
  char color[COL_LEN];

public:
  lacksDMA(const char *c = "blank", const char *l = "null",
           int r = 0);
  lacksDMA(const char *c, const ABC &rs);
  friend std::ostream &operator<<(std::ostream &os,
                                  const lacksDMA &rs);
};

// derived class with DMA
class hasDMA : public ABC
{
private:
  char *style;

public:
  hasDMA(const char *s = "none", const char *l = "null",
         int r = 0);
  hasDMA(const char *s, const baseDMA &rs);
  hasDMA(const hasDMA &hs);
  ~hasDMA();
  hasDMA &operator=(const hasDMA &rs);
  friend std::ostream &operator<<(std::ostream &os,
                                  const hasDMA &rs);
};

#endif

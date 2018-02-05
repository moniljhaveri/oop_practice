#ifndef CLASS_HPP
#define CLASS_HPP
class Cd
{ // represents a CD disk
private:
  char performers[50];
  char label[20];
  int selections;
  // number of selections
  double playtime; // playing time in minutes
public:
  Cd(char *s1, char *s2, int n, double x);
  Cd(const Cd &d);
  Cd();
  virtual ~Cd();
  virtual void Report() const; // reports all CD data
  Cd &operator=(const Cd &d);
};

class Classic : public Cd
{
private:
  char primaryWork[100];

public:
  Classic();
  Classic(char *s1, char *s2, char *s3, int n, double x);
  ~Classic();
  void Report() const;
  Classic &operator=(const Cd &d);
};
#endif
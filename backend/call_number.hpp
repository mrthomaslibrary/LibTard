#pragma once
#include <string>

class CallNumber {
  private:
  std::string gClass;
  float subject;
  std::string cutter;
  int copy;
  std::string fullCallNumber;

  public:
  CallNumber(const std::string gc, const float s, const std::string c, const int cy);
  CallNumber();
  ~CallNumber();
  int compare(const CallNumber& cn) const;
  std::string getFullCallNumber() const;

  std::string getGClass() const;
  float getSubject() const;
  std::string getCutter() const;
  int getCopy() const;

};

#include "call_number.hpp"
#include <random>
#include <sstream>
#include <iomanip>

CallNumber::CallNumber(std::string gn, float s, std::string c, int cy) {
  gClass = gn;
  subject = s;
  cutter = c;
  copy = cy;
  std::ostringstream oss;
  oss << gn << std::fixed << std::setprecision(2) << s << " " << c;
  if (cy > 1) {
    oss << " c." << cy;
  }
  fullCallNumber = oss.str();
}

CallNumber::CallNumber() {
  gClass = "\0";
  subject = 0;
  cutter = "\0";
  copy = 0;
  fullCallNumber = "\0";
}

CallNumber::~CallNumber() {}

int CallNumber::compare(const CallNumber& cn) const {
  if (gClass < cn.gClass) {return 1;}  else if (gClass > cn.gClass) {return -1;}
  if (subject < cn.subject) {return 1;} else if (subject > cn.subject) {return -1;}
  if (cutter < cn.cutter) {return 1;} else if (cutter > cn.cutter) { return -1;}
  if (copy < cn.copy) { return 1;} else if (copy > cn.copy) { return -1;}
  return 0;
}

std::string CallNumber::getFullCallNumber() const {
  return fullCallNumber;
}

std::string CallNumber::getGClass() const {
  return gClass;
}

float CallNumber::getSubject() const {
  return subject;
}

std::string CallNumber::getCutter() const {
  return cutter;
}

int CallNumber::getCopy() const {
  return copy;
}

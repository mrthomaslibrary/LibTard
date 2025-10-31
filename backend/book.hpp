#pragma once
#include "call_number.hpp"
#include <string>

class Book {
private:
  CallNumber callnum;
  std::string title;
  std::string author;
  int barcode;

public:
  Book(const CallNumber cn, const std::string t, const std::string a, int newBarcode);
  ~Book();
  CallNumber getCallNumber() const;
  std::string getTitle() const;
  std::string getAuthor() const;
};

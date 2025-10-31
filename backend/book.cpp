#include "book.hpp"
#include "call_number.hpp"
#include <string>

Book::Book(const CallNumber cn, const std::string t, const std::string a, int newBarcode) {
  callnum = cn;
  title = t;
  author = a;
  barcode = newBarcode;
}

Book::~Book() {}

CallNumber Book::getCallNumber() const {
  return callnum;
}

std::string Book::getTitle() const {
  return title;
}

std::string Book::getAuthor() const {
  return author;
}

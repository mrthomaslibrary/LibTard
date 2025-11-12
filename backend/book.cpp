#include "book.hpp"
#include <string>


Book::Book(const int newBarcode, const string newTitle, const string newAuthor, const string newCallNumber) {
  barcode = newBarcode;
  title = newTitle;
  author = newAuthor;
  callNumber = newCallNumber;
}

Book::~Book() {}

string Book::getCallNumber() const { return callNumber; }

std::string Book::getTitle() const { return title; }

std::string Book::getAuthor() const { return author; }

int Book::getBarcode() const { return barcode; }

void Book::setLoan(int id) { loanedTo = id; }

int Book::getLoanedTo() { return loanedTo; }

int validateCallNumber(string cn) {
  return 0;
}

BookList::BookList() {}

BookList::~BookList() {}

int BookList::addBook(const int newBarcode, const string newTitle, const string newAuthor, const string newCallNumber) {
  if (bookList[newBarcode]) {
    return 305;
  }
  else {
    Book* newBook = new Book(newBarcode, newTitle, newAuthor, newCallNumber);
    bookList[newBarcode] = newBook;
    if (bookList[newBarcode]->getBarcode()  == newBarcode) {
      return 301;
    }
    size++;
    return 302;
  }
  return 302;
}

Book* BookList::getBook(int n) { return bookList[n]; }

int BookList::getSize() { return size; }

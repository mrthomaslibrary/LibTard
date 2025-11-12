#pragma once
#define MAX_BOOKS 1000
#include <string>
using std::string;

class Book {
private:
  string callNumber;
  string title;
  string author;
  int barcode;
  int loanedTo;

public:
  Book(const int newBarcode, const string newTitle, const string newAuthor, const string newCallNumber);
  ~Book();
  string getCallNumber() const;
  string getTitle() const;
  string getAuthor() const;
  int getBarcode() const;
  void setLoan(int id);
};

int validateCallNumber(string cn);

struct BookTemplate {
  Book *emptyBook = new Book(0, "", "", "");
};

class BookList {
private:
  int size;
  BookTemplate bookTemplates;
public:
  BookList();
  ~BookList();
  Book *bookList[MAX_BOOKS];
  int addBook(const int newBarcode, const string newTitle, const string newAuthor, const string newCallNumber);
  Book* getBook(int n);
};

#include <string>

#include "book.hpp"
#include "linked_list.hpp"

class Patron {
private:
  int id;
  std::string name;
  LinkedList<Book> bookList;
  LinkedList<Book> requestList;
public:
  Patron();
  ~Patron();
  void checkoutBook(int barcode);
  void returnBook(int barcode);
  void requestBook(int barcode);
};

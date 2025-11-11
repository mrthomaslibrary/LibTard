#define MAX_PATRONS 100

#include <string>

#include "book.hpp"
#include "linked_list.hpp"

class Patron {
private:
  int id;
  std::string name;
  std::string patronType;

  int numBooksLoaned;
  LinkedList<Book> loanList;
  int numBookRequested;
  LinkedList<Book> requestList;
public:
  Patron(int newId, std::string newName, std::string newPatronType);
  ~Patron();
  int getId();
  std::string getName();
  std::string getPatronType();
  void loanBook(int barcode);
  void returnBook(int barcode);
  void requestBook(int barcode);
  void removeRequest(int n);
};

struct PatronTemplate {
  Patron *emptyPatron = new Patron(0, "", "");
};

class PatronList {
private:
  int size;
  PatronTemplate patronTemplates;
public:
  PatronList();
  ~PatronList();
  Patron *patronList[MAX_PATRONS];
  int addPatron(std::string newId, std::string newName, std::string newPatronType);
  Patron* getPatron(int n);
};

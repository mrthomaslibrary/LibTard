#include <string>
#include <vector>

#include "patron_list.hpp"

using std::string;

class Terminal {
private:
  
public:
  Terminal();
  ~Terminal();
  PatronList patrons;
  BookList books;
  int runCommand();
  int recentPatron;
  int recentBook;
};

void parseCommand(std::vector<string>& commandTerms);

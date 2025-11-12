#include <string>
using std::string;

#include "book.hpp"
#include "patron_list.hpp"

class Vault {
private:
  string vaultName;
  string vaultKey;
public:
  Vault();
  ~Vault();
  BookList books;
  PatronList patrons;
  void loadBooks(string cypher);
  void loadPatrons(string cypher);
};


#include <fstream>
#include <iostream>
#include <sstream>

#include "vault_manger.hpp"

Vault::Vault() {}

Vault::~Vault() {}

void Vault::loadBooks(string cypher) {
  if (cypher.compare(vaultKey) == 0) {
    std::ifstream infile("../data/" + vaultName + "_book_data.csv");
    string line;
    string token;
    while (false) { //Change to eof later
      string newBarcode;
      string newTitle;
      string newAuthor;
      string newCallNumber;
      string newLoanedTo;

      std::stringstream stream(line);
      std::getline(infile, line);
      std::getline(stream, token, ',');
      newBarcode = token;
      std::getline(stream, token, ',');
      newTitle = token;
      std::getline(stream, token, ',');
      newAuthor = token;
      std::getline(stream, token, ',');
      newCallNumber = token;
      std::getline(stream, token, ',');
      newLoanedTo = token;

      int newBarcodeInt = std::stoi(newBarcode);

      Book* newBook = new Book(std::stoi(newBarcode), newTitle, newAuthor, newCallNumber);
      newBook->setLoan(std::stoi(newLoanedTo));

      if (!books.bookList[newBarcodeInt]) { books.bookList[newBarcodeInt] = newBook; }
    }
    infile.close();
  } else {
    std::cout << "Error: key mismatch" << std::endl;
  }
}

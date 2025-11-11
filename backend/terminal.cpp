#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "terminal.hpp"
using std::string;

Terminal::Terminal() {
  recentPatron = 0;
}

Terminal::~Terminal() {}

int Terminal::runCommand() {
  
  std::vector<string> commandTerms;

  parseCommand(commandTerms);

  if (commandTerms[0] == "quit") {

    return 110;

  } else if (commandTerms[0] == "clear") {

    system("clear");

  } else if (commandTerms[0] == "displayPatron") {
    if (commandTerms.size() < 2) {
      std::cout << "Error: Invalid Syntax" << std::endl;
    } else {  
      try {
        int index;
        if (commandTerms[1] == "recentPatron") {
        index = recentPatron;
        } else {
          index = std::stoi(commandTerms[1]);
        }
        Patron *currentPatron = patrons.patronList[index];
        if (!currentPatron) {
          throw std::runtime_error("non-existant patron");
        }
        std::cout << "Patron:" << std::endl;
        std::cout << "Id:\t\t\t|\t"<< std::to_string(currentPatron->getId()) << std::endl;
        std::cout << "Name:\t\t\t|\t" << currentPatron->getName() << std::endl;
        std::cout << "Patron Type:\t\t|\t" << currentPatron->getPatronType() << std::endl;
        std::cout << "Books on loan:\t\t|\t" << currentPatron->getNumBooksRequested() << std::endl;
        std::cout << "Book requested:\t|\t" << currentPatron->getNumBooksRequested() << std::endl;
        recentPatron = index;
      } catch (const std::invalid_argument& e) {
        std::cout << "Error: Invalid Syntax, \"" << commandTerms[1] << "\" not an Integer" << std::endl;
      } catch (const std::out_of_range& e) {
        std::cout << "Error: Invalid Syntax, out of range" << std::endl;
      } catch (const std::runtime_error& e) {
        std::cout << "Error: Invalid Syntax, non-existant patron" << std::endl;
      }
    }
  } else if (commandTerms[0] == "addPatron") {
    
    int returnCode = 405;

    do {
      string newId;
      string newName;
      string newPatronType;
      std::cout << "Enter Patron Id: ";
      std::getline(std::cin, newId);
      std::cout << "Enter Patron Name: ";
      std::getline(std::cin, newName);
      std::cout << "Enter Patron Type: ";
      std::getline(std::cin, newPatronType);
      returnCode = patrons.addPatron(newId, newName, newPatronType);
      if (returnCode == 405) { std::cout << "Error adding patron" << std::endl; }
      else { recentPatron = std::stoi(newId); }
    } while ( returnCode == 405);
  } else if (commandTerms[0] == "addBook") {
    int returnCode = 305;
    do {
      string newBarcode;
      string newTitle;
      string newAuthor;
      string newCallNumber;
      std::cout << "Enter Barcode: ";
      std::getline(std::cin, newBarcode);
      std::cout << "Enter Title: ";
      std::getline(std::cin, newTitle);
      std::cout << "Enter Author: ";
      std::getline(std::cin, newAuthor);
      std::cout << "Enter CallNumber: ";
      std::getline(std::cin, newCallNumber);
      returnCode = books.addBook(std::stoi(newBarcode), newTitle, newAuthor, newCallNumber);
      recentBook = std::stoi(newBarcode);
    } while (returnCode == 305);
  } else if (commandTerms[0] == "displayBook") {
    if (commandTerms.size() < 2) {
      std::cout << "Error: Invalid Syntax" << std::endl;
    } else {
      try {
        int index;
        if (commandTerms[1] == "recentBook") { index = recentBook; }
        else { index = std::stoi(commandTerms[1]); }
        Book* currentBook = books.bookList[index];
        if (!currentBook) { throw std::runtime_error("non-existant book"); }
        std::cout << "Book: " << std::endl;
        std::cout << "Barcode:\t|\t" << std::to_string(currentBook->getBarcode()) << std::endl;
        std::cout << "Title:\t\t|\t" << currentBook->getTitle() << std::endl;
        std::cout << "Author:\t\t|\t" << currentBook->getAuthor() << std::endl;
        std::cout << "CallNumber:\t|\t" << currentBook->getCallNumber() << std::endl;
        recentBook = index;
      } catch (const std::invalid_argument& e) {
        std::cout << "Error: Invalid Syntax, \"" << commandTerms[1] << "\" not an integer" << std::endl;
      } catch (const std::out_of_range& e) {
        std::cout << "Error: Invalid Syntax, out of range" << std::endl;
      } catch (const std::runtime_error& e) {
        std::cout << "Error: Invalid Syntax, non-existant book" << std::endl;
      }
    }
  }
  return 101;
}

void parseCommand(std::vector<string>& commandTerms) {
  commandTerms.clear(); // Clear the vector to remove any existing elements
  std::string input;
  std::cout << "> ";
  std::getline(std::cin, input); // Read a line from standard input
  std::stringstream ss(input);
  std::string term;
  while (ss >> term) {
    commandTerms.push_back(term);
  }
}



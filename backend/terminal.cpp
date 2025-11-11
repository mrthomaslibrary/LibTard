#include <iostream>
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
        std::cout << "Id:\t\t|\t"<< std::to_string(currentPatron->getId()) << std::endl;
        std::cout << "Name:\t\t|\t" << currentPatron->getName() << std::endl;
        std::cout << "Patron Type:\t|\t" << currentPatron->getPatronType() << std::endl;
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
  } else {

    return 100;
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



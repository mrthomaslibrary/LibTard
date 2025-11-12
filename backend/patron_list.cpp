#include "patron_list.hpp"

Patron::Patron(int newId, std::string newName, std::string newPatronType) {
  id = newId;
  name = newName;
  patronType = newPatronType;
  numBooksLoaned = 0;
  numBookRequested = 0;
}

Patron::~Patron() {}

int Patron::getId() { return id; }

std::string Patron::getName() { return name; }

std::string Patron::getPatronType() { return patronType; }

int Patron::getNumBooksLoaned() { return numBooksLoaned; }

int Patron::getNumBooksRequested() { return numBookRequested; }

PatronList::PatronList() {
  size = 0;
}

PatronList::~PatronList() {}

int PatronList::addPatron(std::string newId, std::string newName, std::string newPatronType) {
  int newIntId = std::stoi(newId);
  Patron *newPatron = new Patron(newIntId, newName, newPatronType);
  if (patronList[newIntId]) {
    return 405;
  } else {
    patronList[newIntId] = newPatron;
    if (patronList[newIntId]->getId() == newIntId) { 
      size++;
      return 401; 
    }
    else { 
      delete newPatron;
      return 403;
    }
  }
  return 402;
}

Patron* PatronList::getPatron(int n) {
  if (patronList[n]) {
    return patronList[n];
  }
  else { return patronTemplates.emptyPatron; }
}

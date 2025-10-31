#include "call_number.hpp"
#include "book.hpp"
#include "cart.hpp"

#include <iostream>

int main(void) {
  Cart cart;
  Book *b1 = new Book(CallNumber("QA", 76.73, "J38", 2023), "Nut in me Butthole", "Dick wetts");
  Book *b2 = new Book(CallNumber("H", 76.73, "J38", 2023), "Big Shit", "Nert"); 
  Book *b3 = new Book(CallNumber("HS", 76.73, "J38", 2023), "Kids are Weird", "Dick Brown");
  Book *b4 = new Book(CallNumber("QA", 76.73, "A", 0), "Nut", "Blue McGreen"); 

  cart.addBook(b1);
  cart.addBook(b2);
  cart.addBook(b3);
  cart.addBook(b4);

  cart.displayCart();

  std::cout << cart.rootBook->nextGClass->getCallNumber().getFullCallNumber() << std::endl;

  return 0;
}

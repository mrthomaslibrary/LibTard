#include <iostream>
#include <string>

#include "terminal.hpp"

int main(void) {

  int returnCode = 0;
  Terminal terminal;
  std::string line;

  system("clear");
  std::cout << "LibTard (c) 2025 MrThomasLibrary\n\nWelcome to LibTard!" << std::endl;

  do {
    returnCode = terminal.runCommand();
  } while (returnCode != 110);

  return 0;
}

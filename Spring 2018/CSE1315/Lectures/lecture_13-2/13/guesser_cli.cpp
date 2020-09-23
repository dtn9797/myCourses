#include <iostream>
#include <random>

int main() {
    int num;        // The number to be guessed
    int guess = 0;  // The user's guess
    std::string text;    // Temp for holding user's input

    srand ( time(NULL) );
    num = rand() % 100 + 1;

    while (num != guess) {
      std::cout << "What is your guess (0 to 100): ";
      std::getline(std::cin, text);
      guess = atoi(text.c_str());
      if (guess < 1 || guess > 100) std::cerr << "Out of range!" << std::endl;
      else if (guess > num) std::cout << "Too high!" << std::endl;
      else if (guess < num) std::cout << "Too low!" << std::endl;
      else std::cout << "WINNER!" << std::endl;
    }
}

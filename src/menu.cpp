#include "menu.h"

#include <iomanip>
#include <iostream>

void Menu::displayPlayerNamePrompt() {

  std::string playerName;

  std::cout << "Please enter your name: ";
  std::cin >> playerName;

  if (std::cin.fail()) {
    playerName = "< N/A >";
    std::cerr << "Wrong Input" << std::endl;
  }

  _playerName = std::move(playerName);
};

void Menu::displayPlayerScore(std::string name, int score, int size) {
  std::cout << "Game has terminated succesfully!\n";
  std::cout << "Player Name: " << name << "\n";
  std::cout << "Score: " << score << "\n";
};

std::string Menu::getPlayerName() {
  return _playerName;
}
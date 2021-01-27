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

void Menu::displayPlayerContinuePrompt() {

  std::string playerContinues = "Yes";

  std::cout << "Do you want to play again? (type capital N to quit, otherwise I'll "
               "take it as a yes :-) ";
  std::cin >> playerContinues;

  if (playerContinues == "N") {
    _playerWantsToPlay = false;
  }
}

void Menu::displayPlayerScore(int score) {
  std::cout << "Your Score was: " << score << "\n";
  std::cout << "The game has terminated succesfully, WELCOME BACK!" << "\n";
};

std::string const Menu::getPlayerName() { return _playerName; }

bool const Menu::getPlayerWantsToPlay() { return _playerWantsToPlay; }
#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
  void displayPlayerNamePrompt();
  void displayPlayerScore(std::string name, int score, int size);
  std::string getPlayerName();

private:
  std::string _playerName;
};

#endif
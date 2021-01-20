#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
  void displayPlayerNamePrompt();
  void displayPlayerScore(int score);
  std::string const getPlayerName();

private:
  std::string _playerName;
};

#endif
#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
  void displayPlayerNamePrompt();
  void displayPlayerContinuePrompt();
  void displayPlayerScore(int score);
  std::string const getPlayerName();
  bool const getPlayerWantsToPlay();

private:
  std::string _playerName = "blank";
  bool _playerWantsToPlay = 1;
};

#endif
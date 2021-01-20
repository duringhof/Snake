#include "player.h"

#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>

Player::Player(std::string name) : _name(name) { _score = 0; }

Player::Player(std::string name, int score) : _name(name), _score(score) {}

int Player::getScore() const { return _score; }

void Player::setScore(const int &score) { _score = score; }

void Player::incrementScore() { _score++; }

std::string Player::getName() const { return _name; }

void Player::saveScore() {

  std::vector<Player> players;
  bool isNewPlayer{true};
  int score;
  std::string line;
  std::string name;
  std::ifstream file;

  file.open(HIGHSCORES_FILENAME);

  if (file) {
    while (getline(file, line)) {
      std::istringstream lineStream(line);
      lineStream >> name;
      lineStream >> score;
      if (name == this->_name) {
        if (score < this->_score) {
          score = this->_score;
          std::cout << "Nice game " << name << " !!! You have crushed your record!\n";
        } else {
          std::cout << "Come on " << name << " !!! You were better before!\n";
        }
        isNewPlayer = false;
      }
      players.push_back(Player(name, score));
    }
    file.close();
  }

  if (isNewPlayer) {
    players.push_back(Player(this->_name, this->_score));
  }

  std::sort(players.begin(), players.end(),
            [](const Player a, const Player &b) -> bool {
              return a._score > b._score;
            });

  for (int i = 0; i < 3; i++) {
    if (players[i]._name == this->_name) {
      switch (i) {
      case 0:
        std::cout << "You rank 1st, you're the BEST !!! \n";
        break;
      case 1:
        std::cout << "You rank 2nd, soon you will win !!! \n";
        break;
      case 2:
        std::cout << "You rank 3rd, so you have joined the very best !!! \n";
        break;
      }
    }
  }

  std::ofstream fout;
  fout.open(HIGHSCORES_FILENAME, std::ofstream::trunc);
  for (auto &player : players) {
    fout << player._name << " " << std::to_string(player._score) << std::endl;
  }
  fout.close();
}
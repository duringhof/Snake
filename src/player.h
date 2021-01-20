#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#define HIGHSCORES_FILENAME "highscores.txt"

class Player {
  
public:
  explicit Player(std::string name);
  Player(std::string name, int score);

  int getScore() const;
  void setScore(const int &score);
  void incrementScore();
  void saveScore();

  std::string getName() const;
  
private:
  std::string _name;
  int _score{0};
};

#endif
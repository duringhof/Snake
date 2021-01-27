#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "menu.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Menu menu;

  while (menu.getPlayerWantsToPlay() == true) {

    if (menu.getPlayerName() == "blank") {
      menu.displayPlayerNamePrompt();
    }

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight, menu);
    game.Run(controller, renderer, kMsPerFrame);
    menu.displayPlayerContinuePrompt();
  }
  
  return 0;
}
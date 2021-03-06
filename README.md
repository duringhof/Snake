# Snake

Reinventing the good old first experiences with computers :-)

This is an implementation of the game "Snake", under construction for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code in this repo is based on a ["starter repo"](https://github.com/udacity/CppND-Capstone-Snake-Game.git) provided by Udacity which in turn was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project concerned the integration of learnings throughout this program.

## Changes implemented
Here, I will list and describe the changes I made to complete this project:

1. Update this README.md to reflect current repository content. While listed first, this reflects an activitiy that I try to continuously iterate in sync with the changes I make.

2. Implemented some simple bug and style fixes:
    * Food placement in the original code could be outside the visible area because placement occured in a space that was 1 "block" wider and higher than the define gridwidth and gridheight.
    * The object Snake is passed to the Renderer object by const reference instead of const value to prevent the program from creating a copy of the object.
    * The initialization order for the Snake constructor is changed to resemble the declaration order of variables.
    * The initialization for the Snake constructor involved an implicit int to float conversion, which is now made explicit.

3. Added Player and Menu classes, respectively holding functionality to maintain a highscore record and to provide a user prompt asking for player name at the start of the game.

4. Refined the Player class to compare result with previous results in case they exist, and to bring some extra reward to those that end up in the top 3.

5. Implemented a wall around the playable area that can't be crossed.

## Structure of the code

Main.cpp instantiates 4 objects:

   * Menu (the object that asks the player to enter a name)
   * Renderer (the object that renders the actual playing screen)
   * Controller (the object that handles userinput while playing the game)
   * Game (Updating the steps in the game loop)
         * This class also instantiates a Snake and a Player object respectively holding the functionality related to snake position and the functionality related to scoring the players performance.
         
## Project criteria adressed:

* All criteria related to "Loops, Functions and I/O"
* The first five criteria related to "Object Oriented Programming"
* The first two criteria related to "Memory Management"

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

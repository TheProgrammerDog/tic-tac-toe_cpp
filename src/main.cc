/**
 * @file main.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "tictactoe.h"
#include <iostream>

int main (int argc, char** argv) {
  TicTacToe game(3);
  game.Place(0);
  game.Place(0);
  game.Place(0);
  std::cout << std::endl;

  game.Print();
  std::cout << game.CheckForWin(0) << std::endl;
  return 0;
}
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
  game.Print();
  game.Place(0);
  game.Print();
  
  return 0;
}
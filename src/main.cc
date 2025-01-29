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
  TicTacToe game(4);
  game.Print();
  TicTacToe game2(5);
  game2.Print();
  return 0;
}
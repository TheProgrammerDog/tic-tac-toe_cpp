/**
 * @file main.cc
 * @author AnormalDog
 * @brief main file
 * @version 0.1
 * @date 2025-01-29 
 */

#include "tictactoe.h"
#include <iostream>

/**
 * @brief main function of the program
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main (int argc, char** argv) {
  TicTacToe game(6);
  game.Run();
  return 0;
}
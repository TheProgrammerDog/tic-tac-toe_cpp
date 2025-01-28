/**
 * @file tictactoe.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "tictactoe.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <cstdlib>

TicTacToe::TicTacToe(const unsigned size) {
  resize(size);
  for (auto iter = begin(); iter != end(); ++iter) {
    iter->resize(size);
  }
  fill();
}

void TicTacToe::fill() {
  for (auto iter_1 = begin(); iter_1 != end(); ++iter_1) {
    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2) {
      *iter_2 = VALUES::EMPTY;
    }
  }
}

void TicTacToe::print() const {
  for (auto iter_1 = begin(); iter_1 != end(); ++iter_1) {
    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2) {
      switch (*iter_2) {
        case VALUES::X:
          std::cout << "X ";
        break;
        case VALUES::O:
          std::cout << "O ";
        break;
        default:
          std::cout << "  ";
        break;
      }
    }
  }
}

void TicTacToe::place(const bool player) {
  unsigned x, y;
  std::cout << "Introduce x cord: ";
  std::cin >> x;
  system("clear");
  std::cout << "Introduce y cord: ";
  std::cin >> y;
  system("clear");
  if (player == 0) {
    this->at(x).at(y) = VALUES::X;
  }
  this->at(x).at(y) = VALUES::O;
}
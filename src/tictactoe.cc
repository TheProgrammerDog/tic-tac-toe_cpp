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
#include <string>

std::string values_to_string(const Values value) {
  switch (value) {
    case Values::X:
      return "X";
      break;
    case Values::O:
      return "O";
      break;
    default:
      return " ";
  }
}

Directions index_to_directions(const unsigned value) {
  switch (value) {
    case 0:
      return Directions::North;
      break;
    case 1:
      return Directions::NorthWest;
      break;
    case 2:
      return Directions::West;
      break;
    case 3:
      return Directions::SouthWest;
      break;
    case 4:
      return Directions::South;
      break;
    case 5:
      return Directions::SouthEast;
      break;
    case 6:
      return Directions::East;
      break;
    default:
      return Directions::NorthEast;
  }
}

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
      *iter_2 = Values::Empty;
    }
  }
}

void TicTacToe::print() const {
  for (auto iter_1 = begin(); iter_1 != end(); ++iter_1) {
    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2) {
      std::cout << values_to_string(*iter_2) << " ";
    }
    std::cout << std::endl;
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
    this->at(x).at(y) = Values::X;
  }
  this->at(x).at(y) = Values::O;
}

bool TicTacToe::check_for_win(const bool player, const position pos) const {
  for (unsigned i = 0; i < 8; ++i) {

  }
}

unsigned TicTacToe::check_for_win_recursive(const bool& player, 
const position pos, const Directions& dir) const {
  position new_pos = get_new_pos(pos, dir);
}

position TicTacToe::get_new_pos(const position pos, const Directions dir) const {
  switch (dir) {
    case 0:

      break;
    case 1:

      break;
    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
    case 5:

      break;
    case 6:

      break;
    default:
  }
}
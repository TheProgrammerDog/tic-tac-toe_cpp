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

std::string ValuesToString(const Values& value) {
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

Values BoolToValues(const bool& var) {
  if (var == 1) {
    return Values::X;
  }
  return Values::O;
}

Directions IndexToDirections(const unsigned& value) {
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
  matrix_.resize(size);
  for (auto iter = matrix_.begin(); iter != matrix_.end(); ++iter) {
    iter->resize(size);
  }
  Fill();
}

void TicTacToe::Place(const bool player) {
  unsigned x, y;
  std::cout << "Introduce x cord: ";
  std::cin >> x;
  //system("clear");
  std::cout << "Introduce y cord: ";
  std::cin >> y;
  //system("clear");
  matrix_[x][y] = BoolToValues(player);
}

void TicTacToe::Print() const {
  for (auto iter_1 = matrix_.begin(); iter_1 != matrix_.end(); ++iter_1) {
    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2) {
      std::cout << ValuesToString(*iter_2) << " ";
    }
    std::cout << std::endl;
  }
}

Values TicTacToe::GetValueOn(const Position& pos) const {
  return matrix_[pos.first][pos.second];
}

void TicTacToe::Fill() {
  for (auto iter_1 = matrix_.begin(); iter_1 != matrix_.end(); ++iter_1) {
    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2) {
      *iter_2 = Values::Empty;
    }
  }
}

Position TicTacToe::GetNewPos(const Position& pos, const Directions& dir) const {
  Position new_pos;
  switch (dir) {
    case North:
      new_pos.first = pos.first + 1;
      new_pos.second = pos.second;
      break;
    case NorthWest:
      new_pos.first = pos.first + 1;
      new_pos.second = pos.second - 1; 
      break;
    case West:
      new_pos.first = pos.first;
      new_pos.second = pos.second - 1; 
      break;
    case SouthWest:
      new_pos.first = pos.first - 1;
      new_pos.second = pos.second - 1; 
      break;
    case South:
      new_pos.first = pos.first - 1;
      new_pos.second = pos.second; 
      break;
    case SouthEast:
      new_pos.first = pos.first - 1;
      new_pos.second = pos.second + 1; 
      break;
    case East:
      new_pos.first = pos.first;
      new_pos.second = pos.second + 1; 
      break;
    default: // NorthEast
      new_pos.first = pos.first + 1;
      new_pos.second = pos.second + 1; 
  }
  return new_pos;
}

bool TicTacToe::CheckForLegalPos(const Position& pos) const {
  if (pos.first >= matrix_.size() || pos.second >= matrix_.size() || 
  pos.first < 0 || pos.second < 0) {
    return false;
  }
  return true;
}

bool TicTacToe::CheckForWin(const bool player, const Position& pos) const {
  for (unsigned i = 0; i < 8; ++i) {
    if (CheckForWinRecursive(player, pos, IndexToDirections(i)) == matrix_.size()) {
      return true;
    }
  }
  return false;
}

unsigned TicTacToe::CheckForWinRecursive(const bool& player, 
const Position& pos, const Directions& dir) const {
  Position new_pos = GetNewPos(pos, dir);
  // General Case
  if ((CheckForLegalPos(new_pos)) && (BoolToValues(player) == GetValueOn(new_pos))) {
    return (1 + CheckForWinRecursive(player, new_pos, dir));
  }
  // Base Case
  return 0;
}

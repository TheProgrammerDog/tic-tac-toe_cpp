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

std::string ValueToString(const Value& value) {
  switch (value) {
    case Value::X:
      return "X";
      break;
    case Value::O:
      return "O";
      break;
    default:
      return " ";
  }
}

Value BoolToValue(const bool& var) {
  if (var == 1) {
    return Value::X;
  }
  return Value::O;
}

Direction IndexToDirection(const unsigned& value) {
  switch (value) {
    case 0:
      return Direction::North;
      break;
    case 1:
      return Direction::NorthWest;
      break;
    case 2:
      return Direction::West;
      break;
    case 3:
      return Direction::SouthWest;
      break;
    case 4:
      return Direction::South;
      break;
    case 5:
      return Direction::SouthEast;
      break;
    case 6:
      return Direction::East;
      break;
    default:
      return Direction::NorthEast;
  }
}

TicTacToe::TicTacToe(const unsigned& size) {
  matrix_.resize(size);
  for (auto iter = matrix_.begin(); iter != matrix_.end(); ++iter) {
    iter->resize(size);
  }
  Fill();
}

void Run() {

}

void TicTacToe::Place(const bool& player) {
  unsigned x, y;
  std::cout << "Introduce x cord: ";
  std::cin >> x;
  //system("clear");
  std::cout << "Introduce y cord: ";
  std::cin >> y;
  //system("clear");
  matrix_[x][y] = BoolToValue(player);
  std::cout << std::endl;
}

void TicTacToe::Print() const {
  for (auto iter_1 = matrix_.begin(); iter_1 != matrix_.end(); ++iter_1) {
    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2) {
      std::cout << ValueToString(*iter_2) << " ";
    }
    std::cout << std::endl;
  }
}

Value TicTacToe::GetValueOn(const Position& pos) const {
  return matrix_[pos.first][pos.second];
}

void TicTacToe::Fill() {
  for (auto iter_1 = matrix_.begin(); iter_1 != matrix_.end(); ++iter_1) {
    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2) {
      *iter_2 = Value::Empty;
    }
  }
}

Position TicTacToe::GetNewPos(const Position& pos, const Direction& dir) const {
  Position new_pos;
  switch (dir) {
    case North:
      new_pos.first = pos.first - 1;
      new_pos.second = pos.second;
      break;
    case NorthWest:
      new_pos.first = pos.first - 1;
      new_pos.second = pos.second - 1; 
      break;
    case West:
      new_pos.first = pos.first;
      new_pos.second = pos.second - 1; 
      break;
    case SouthWest:
      new_pos.first = pos.first + 1;
      new_pos.second = pos.second - 1; 
      break;
    case South:
      new_pos.first = pos.first + 1;
      new_pos.second = pos.second; 
      break;
    case SouthEast:
      new_pos.first = pos.first + 1;
      new_pos.second = pos.second + 1; 
      break;
    case East:
      new_pos.first = pos.first;
      new_pos.second = pos.second + 1; 
      break;
    default: // NorthEast
      new_pos.first = pos.first - 1;
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

bool TicTacToe::CheckForWin(const bool& player) const {
  for (unsigned x = 0; x < matrix_.size(); ++x) {
    for (unsigned y = 0; y < matrix_.size(); ++y) {
      for (unsigned dir = 0; dir < 8; ++dir) {
        if (CheckForWinRecursive(player, {x, y}, IndexToDirection(dir)) == matrix_.size()) {
          return true;
        }
      }
    }
  }
  return false;
}

unsigned TicTacToe::CheckForWinRecursive(const bool& player, 
const Position& pos, const Direction& dir) const {
  Position new_pos = GetNewPos(pos, dir);
  // General Case
  if ((CheckForLegalPos(new_pos)) && (BoolToValue(player) == GetValueOn(new_pos))) {
    return (1 + CheckForWinRecursive(player, new_pos, dir));
  }
  // Base Case
  return 1;
}
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
  assert (size > 0 && size < 10);
  matrix_.resize(size);
  for (auto iter = matrix_.begin(); iter != matrix_.end(); ++iter) {
    iter->resize(size);
  }
  Fill(Value::O);
}

bool TicTacToe::Run(const bool& player) {
  Fill();
}

void TicTacToe::Place(const bool& player) {
  system("clear");
  std::string x_raw, y_raw;
  bool correct_input {0};
  Position pos;
  while (correct_input == 0) {
    std::cout << "Introduce x and y cord: ";
    std::cin >> x_raw >> y_raw;
    if (!CheckForValidInput(x_raw) || !CheckForValidInput(y_raw)) {
      std::cout << "invalid input, try again" << std::endl;
      continue;
    }
    unsigned x = static_cast<unsigned>(x_raw[0] - 48);
    unsigned y = static_cast<unsigned>(y_raw[0] - 48);
    pos = {x, y};
    if (CheckForLegalPos(pos)) {
      correct_input = 1;
      matrix_[x][y] = BoolToValue(player);
    }
    else {
      std::cout << "Invalid position, try again" << std::endl;
      continue;
    }
  }

}

void TicTacToe::Print() const {
  std::cout << "    ";
  for (size_t i = 0; i < matrix_.size(); ++i) {
    std::cout << i << " ";
  }
  std::cout << std::endl << "  ┌";
  for (size_t i = 0; i < matrix_.size() * 2 + 1; ++i) {
    std::cout << "─";
  }
  std::cout << "┐" << std::endl;
  for (size_t i = 0; i < matrix_.size(); ++i) {
    std::cout << i << " │ ";
    for (size_t j = 0; j < matrix_.size(); ++j) {
      std::cout << ValueToString(matrix_[i][j]) << " ";
    }
    std::cout << "│" << std::endl;
  }
  std::cout << "  └";
  for (size_t i = 0; i < matrix_.size() * 2 + 1; ++i) {
    std::cout << "─";
  }
  std::cout << "┘" << std::endl;
}

Value TicTacToe::GetValueOn(const Position& pos) const {
  return matrix_[pos.first][pos.second];
}

void TicTacToe::Fill(const Value& value) {
  for (auto iter_1 = matrix_.begin(); iter_1 != matrix_.end(); ++iter_1) {
    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2) {
      *iter_2 = value;
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

bool TicTacToe::CheckForValidInput(const std::string& entry) const {
  if (entry.size() == 1 && (entry[0] >=48 && entry[0] <= 57)) {
    return true;
  }
  return false;
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
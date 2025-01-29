/**
 * @file tic-tac-toe.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include <vector>
#include <iostream>
#include <string>

enum class Value {
  Empty,
  X, // 1
  O  // 0
};

enum Direction {
  North,     // 0
  NorthWest, // 1
  West,      // 2
  SouthWest, // 3
  South,     // 4
  SouthEast, // 5
  East,      // 6
  NorthEast  // 7
};

using Position = std::pair<int, int>;

std::string ValueToString(const Value& value);
Value BoolToValue(const bool& var);

Direction IndexToDirection(const unsigned& value);

class TicTacToe {
  public:
    TicTacToe(const unsigned& size);
    ~TicTacToe() {}

    bool Run(const bool& first = 0);

    void Turn(const bool& player);
    Value GetValueOn(const Position& pos) const;
    void Print() const;

  private:
    std::vector<std::vector<Value>> matrix_;
    void Fill(const Value& value = Value::Empty);
    Position GetNewPos(const Position& pos, const Direction& dir) const;
    bool CheckForLegalPos(const Position& pos) const;
    bool CheckForValidInput(const std::string& entry) const;
    bool CheckForWin(const bool& player) const;
    unsigned CheckForWinRecursive(const bool& player, 
      const Position& pos, const Direction& dir) const; 
};

#endif
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

enum class Values {
  Empty,
  X, // 1
  O  // 0
};

enum Directions {
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

std::string ValuesToString(const Values& value);
Values BoolToValues(const bool& var);

Directions IndexToDirections(const unsigned& value);

class TicTacToe {
  public:
    TicTacToe(const unsigned size = 3);
    ~TicTacToe() {}

    bool Run();

    void Place(const bool player);
    Values GetValueOn(const Position& pos) const;
    void Print() const;

  private:
    std::vector<std::vector<Values>> matrix_;
    void Fill();
    Position GetNewPos(const Position& pos, const Directions& dir) const;
    bool CheckForLegalPos(const Position& pos) const;
    bool CheckForWin(const bool player) const;
    unsigned CheckForWinRecursive(const bool& player, 
      const Position& pos, const Directions& dir) const; 
};

#endif
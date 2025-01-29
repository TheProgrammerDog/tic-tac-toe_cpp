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
  X,
  O
};

enum Directions {
  North,
  NorthWest,
  West,
  SouthWest,
  South,
  SouthEast,
  East,
  NorthEast
};

using position = std::pair<unsigned, unsigned>;

std::string values_to_string(const Values value);

Directions index_to_Directions(const unsigned value);

class TicTacToe : public std::vector<std::vector<Values>> {
  public:
    TicTacToe(const unsigned size = 3);
    ~TicTacToe() {}

    bool run();

    void place(const bool player);
    void print() const;
  private:
    void fill();

    bool check_for_win(const bool player, const position pos) const;

    unsigned check_for_win_recursive(const bool& player, 
      const position pos, const Directions& dir) const;

    position get_new_pos(const position pos, const Directions dir) const;
};

#endif
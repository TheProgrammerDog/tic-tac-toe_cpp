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

enum class VALUES {
  EMPTY,
  X,
  O
};

class TicTacToe : public std::vector<std::vector<VALUES>> {
  public:
    TicTacToe(const unsigned size = 3);
    ~TicTacToe() {}

    void place(const bool player);
    void print() const;
  private:
    void fill();
};

#endif
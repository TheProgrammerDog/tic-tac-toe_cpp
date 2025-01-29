/**
 * @file tic-tac-toe.h
 * @author AnormalDog
 * @brief declaration of the TicTacToe class and adjacent methods 
 * @version 0.1
 * @date 2025-01-28
 */

#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include <vector>
#include <iostream>
#include <string>

/**
 * @brief Enumeration for each state a 
 * section position can be
 * 
 */
enum class Value {
  Empty,
  X, // 1
  O  // 0
};

/**
 * @brief Enumeration for each posible 
 * direction in a 2 dimension matrix
 * 
 */
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

/**
 * @brief For simple syntax, defining a using for positions
 * 
 */
using Position = std::pair<int, int>;

/**
 * @brief Return a Printeable string analoge to the value
 * 
 * @param value 
 * @return std::string 
 */
std::string ValueToString(const Value& value);

/**
 * @brief Players are 2, but the states of a direction are 
 * This func assign each player to a value (X or O)
 * 
 * @param var 
 * @return Value 
 */
Value BoolToValue(const bool& var);

/**
 * @brief each direction can be convertable to int
 * This func do the opposite
 * 
 * @param value 
 * @return Direction 
 */
Direction IndexToDirection(const unsigned& value);

/**
 * @brief Main class, represent a TicTacToe of variable size
 * Internally, it is just a matrix
 * 
 */
class TicTacToe {
  public:

  /**
   * @brief Construct a new Tic Tac Toe object
   * 
   */
  TicTacToe();
  /**
   * @brief Construct a new Tic Tac Toe object
   * With variable size
   * 
   * @param size 
   */
    TicTacToe(const unsigned& size);

    /**
     * @brief Destroy the Tic Tac Toe object
     * 
     */
    ~TicTacToe() {}

    /**
     * @brief Start a game
     * 
     * @param first 
     * @return true 
     * @return false 
     */
    bool Run(const bool& first = 0);

    /**
     * @brief Do a turn for a player
     * Take the input
     * Writes it on the matrix
     * 
     * @param player 
     */
    void Turn(const bool& player);

    /**
     * @brief Get the Value on position
     * 
     * @param pos 
     * @return Value 
     */
    Value GetValueOn(const Position& pos) const;

    /**
     * @brief Print the matrix
     * 
     */
    void Print() const;

  private:

    /**
     * @brief Internal attribute of the class
     * 
     */
    std::vector<std::vector<Value>> matrix_;

    /**
     * @brief fill the matrix with a symbol
     * 
     * @param value 
     */
    void Fill(const Value& value = Value::Empty);

    /**
     * @brief Having the position and direction
     * compute the next position
     * 
     * @param pos 
     * @param dir 
     * @return Position 
     */
    Position GetNewPos(const Position& pos, const Direction& dir) const;

    /**
     * @brief Check if the position is valid
     * its cords being inside the matrix
     * 
     * @param pos 
     * @return true 
     * @return false 
     */
    bool CheckForLegalPos(const Position& pos) const;

    /**
     * @brief Check if a Input is valid
     * Takes cin as a string
     * And do multiple checks
     * 
     * @param entry 
     * @return true 
     * @return false 
     */
    bool CheckForValidInput(const std::string& entry) const;

    /**
     * @brief Check all posible win positions and directions
     * 
     * @param player 
     * @return true 
     * @return false 
     */
    bool CheckForWin(const bool& player) const;

    /**
     * @brief 
     * 
     * @param player 
     * @param pos 
     * @param dir 
     * @return unsigned 
     */
    unsigned CheckForWinRecursive(const bool& player, 
    const Position& pos, const Direction& dir) const; 
};

#endif
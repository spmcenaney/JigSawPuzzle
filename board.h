//board.h
#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "cluster.h"
#include <string>
using std::string;
#include "Utilities.h"

class board;       //forward declaration of the board
class Utilities;

class board {
  public:
    //Purpose: Default constructor for the board
    //Pre:
    //Post:
    board();
    //Purpose: Default constructor for the board
    //Pre:
    //Post:
    ~board();
    //Purpose: constructor for the board
    //Pre:
    //Post:
    board(int rows, int cols);
    //Purpose: constructor for the board
    //Pre:
    //Post:
    board(const board &b);
    //Purpose: copy board
    //Pre:
    //Post: copies variables of board to inputted board
    void copy_board(const board &b);
  private:
    Utilities u;
    int m_rows;
    int m_cols;

    void createBoard(int rows, int cols);
    void assignPieces();
    //void printBoard();

    piece** m_pieces;
};
#endif

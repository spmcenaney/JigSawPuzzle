//piece.h
#ifndef PIECE_H
#define PIECE_H

#include "p1.h"
//#include "dungeon.h"
//#include "Utilities.h"

class piece;       //forward declaration of the piece
//class Utilities;

class piece {
  public:
    //Purpose: Default constructor for the piece
    //Pre:
    //Post:
    piece();
    //Purpose: constructor for the piece
    //Pre:
    //Post:
    piece(int left, int top, int right, int bottom);
    //Purpose: constructor for the piece
    //Pre:
    //Post:
    piece(const piece &p);
    //Purpose: Getter for position
    //Pre: Nothing required
    //Post: Returns position
    int getSide(int side) {return m_side[side];}
    //Purpose: setter for position
    //Pre: Nothing required
    //Post:
    void setSide(int side, int value);
    //Purpose: Getter for position
    //Pre: Nothing required
    //Post: Returns position
    int getID() {return m_ID;}
    //Purpose: setter for position
    //Pre: Nothing required
    //Post:
    void setID(int ID);
    //Purpose: Getter for position
    //Pre: Nothing required
    //Post: Returns position
    int getRow() {return m_row;}
    //Purpose: Getter for position
    //Pre: Nothing required
    //Post: Returns position
    int getCol() {return m_col;}
    //Purpose: setter for position
    //Pre: Nothing required
    //Post:
    void setLocation(int row, int col);
    //Purpose: copy piece
    //Pre:
    //Post: copies variables of piece to inputted piece
    void copy_piece(const piece &p);
  private:
    int m_side[4];
    int m_row;
    int m_col;
    int m_ID;
};
#endif

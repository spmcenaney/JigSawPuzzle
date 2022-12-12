//piece.cpp
#include "piece.h"

piece::piece() {           // default constructor
  m_side[LEFT] = -1;
  m_side[TOP] = -1;
  m_side[RIGHT] = -1;
  m_side[BOTTOM] = -1;
  m_row = -1;
  m_col = -1;
  m_ID = -1;
}
piece::piece(int left, int top, int right, int bottom) {
  m_side[LEFT] = left;
  m_side[TOP] = top;
  m_side[RIGHT] = right;
  m_side[BOTTOM] = bottom;
  m_row = -1;
  m_col = -1;
  m_ID = -1;
}
piece::piece(const piece &p) {
  copy_piece(p);
}

void piece::copy_piece(const piece &p) {
  m_side[LEFT] = p.m_side[LEFT];
  m_side[TOP] = p.m_side[TOP];
  m_side[RIGHT] = p.m_side[RIGHT];
  m_side[BOTTOM] = p.m_side[BOTTOM];
  m_row = p.m_row;
  m_col = p.m_col;
  m_ID = p.m_ID;
}

void piece::setSide(int side, int value) {
  m_side[side] = value;
}

void piece::setLocation(int row, int col) {
  m_row = row;
  m_col = col;
}

void piece::setID(int ID) {
  m_ID = ID;
}

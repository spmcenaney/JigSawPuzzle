//cluster.cpp
#include "cluster.h"

cluster::cluster() {           // default constructor
    m_numPieces = 1;
    m_rows = 1;
    m_cols = 1;
}

cluster::~cluster() {           // default constructor
  for (int i = 0; i < m_rows; i ++) {
    delete [] m_pieces[i];
  }
  delete [] m_pieces;
  //m_pieces = nullptr;
}

void cluster::createCluster(int rows, int cols, piece p) {
  m_rows = rows;
  m_cols = cols;
  m_pieces = new piece*[rows];
  for (int i = 0; i < rows; i ++) {
    m_pieces[i] = new piece[cols];
  }
  addPiece(p);
  u.printBoard(m_pieces,rows,cols);
}

void cluster::addPiece(piece p) {
  m_pieces[p.getRow()][p.getCol()].setLocation(p.getRow(),p.getCol());
  m_pieces[p.getRow()][p.getCol()].setID(p.getID());
  m_pieces[p.getRow()][p.getCol()].setSide(LEFT,p.getSide(LEFT));
  m_pieces[p.getRow()][p.getCol()].setSide(TOP,p.getSide(TOP));
  m_pieces[p.getRow()][p.getCol()].setSide(RIGHT,p.getSide(RIGHT));
  m_pieces[p.getRow()][p.getCol()].setSide(BOTTOM,p.getSide(BOTTOM));
}


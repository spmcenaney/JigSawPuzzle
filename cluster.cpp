//cluster.cpp
#include "cluster.h"

#include <stdlib.h> // for malloc

cluster::cluster() {           // default constructor
  m_numPieces = 0;
  m_rows = 0;
  m_cols = 0;
}

cluster::cluster(const cluster &c) {           // default constructor
  copy_cluster(c);
}

cluster::~cluster() {           // default constructor
  for (int i = 0; i < m_rows; i ++) {
    delete [] m_pieces[i];
  }
  if (m_rows > 0) {
    delete [] m_pieces;
  }
  //m_pieces = nullptr;
}

void cluster::copy_cluster(const cluster &c) {
  m_numPieces = c.m_numPieces;
  m_rows = c.m_rows;
  m_cols = c.m_cols;
  m_pieces = new piece*[m_rows];
  for (int i = 0; i < m_rows; i ++) {
    m_pieces[i] = new piece[m_cols];
  }
  for (int i = 0; i < m_rows; i ++) {
    for (int j = 0; j < m_cols; j ++) {
      m_pieces[i][j].copy_piece(c.m_pieces[i][j]);
    }
  }
  m_cluster.clear();
  for (int i = 0; i < c.m_numPieces; i++) {
    m_cluster.push_back(c.m_cluster[i]);
  }
}

void cluster::createCluster(int rows, int cols, piece p) {
  m_rows = rows;
  m_cols = cols;
  m_pieces = new piece*[rows];
  for (int i = 0; i < rows; i ++) {
    m_pieces[i] = new piece[cols];
  }
  addPiece(p);
}

void cluster::addPiece(piece p) {
  m_pieces[p.getRow()][p.getCol()].setLocation(p.getRow(),p.getCol());
  m_pieces[p.getRow()][p.getCol()].setID(p.getID());
  m_pieces[p.getRow()][p.getCol()].setSide(LEFT,p.getSide(LEFT));
  m_pieces[p.getRow()][p.getCol()].setSide(TOP,p.getSide(TOP));
  m_pieces[p.getRow()][p.getCol()].setSide(RIGHT,p.getSide(RIGHT));
  m_pieces[p.getRow()][p.getCol()].setSide(BOTTOM,p.getSide(BOTTOM));
  m_cluster.push_back(m_pieces[p.getRow()][p.getCol()]);
  m_numPieces++;
}

bool cluster::checkPiece(cluster &cl) {
  bool fits = false;
  int r;
  int c;
  piece p;
  for (int j = 0; j < cl.getNumPieces(); j++) {
    p = cl.getPiece(j);
    r = p.getRow();
    c = p.getCol();
    if (p.getSide(LEFT) == 0) {
      if (p.getSide(TOP) == 0) {
        if (p.getSide(RIGHT) == m_pieces[r][c+1].getSide(LEFT)
        || p.getSide(BOTTOM) == m_pieces[r+1][c].getSide(TOP)) {
          fits = true; // top left corner piece
        } 
      } else if (p.getSide(BOTTOM) == 0) {
        if (p.getSide(RIGHT) == m_pieces[r][c+1].getSide(LEFT)
        || p.getSide(TOP) == m_pieces[r-1][c].getSide(BOTTOM)) {
          fits = true; // bottom left corner piece
        }
      } else {
        if (p.getSide(RIGHT) == m_pieces[r][c+1].getSide(LEFT)
        || p.getSide(BOTTOM) == m_pieces[r+1][c].getSide(TOP)
        || p.getSide(TOP) == m_pieces[r-1][c].getSide(BOTTOM)) {
          fits = true; // left side piece
        }
      }
    } else if (p.getSide(TOP) == 0) {
      if (p.getSide(RIGHT) == 0) {
        if (p.getSide(LEFT) == m_pieces[r][c-1].getSide(RIGHT)
        || p.getSide(BOTTOM) == m_pieces[r+1][c].getSide(TOP)) {
          fits = true; // top right corner piece
        } 
      } else {
        if (p.getSide(RIGHT) == m_pieces[r][c+1].getSide(LEFT)
        || p.getSide(BOTTOM) == m_pieces[r+1][c].getSide(TOP)
        || p.getSide(LEFT) == m_pieces[r][c-1].getSide(RIGHT)) {
          fits = true; // top side piece
        }
      }
    } else if (p.getSide(RIGHT) == 0) {
      if (p.getSide(BOTTOM) == 0) {
        if (p.getSide(LEFT) == m_pieces[r][c-1].getSide(RIGHT)
        || p.getSide(TOP) == m_pieces[r-1][c].getSide(BOTTOM)) {
          fits = true; // bottom right corner piece
        } 
      } else {
        if (p.getSide(TOP) == m_pieces[r-1][c].getSide(BOTTOM)
        || p.getSide(BOTTOM) == m_pieces[r+1][c].getSide(TOP)
        || p.getSide(LEFT) == m_pieces[r][c-1].getSide(RIGHT)) {
          fits = true; // right side piece
        }
      }
    } else if (p.getSide(BOTTOM) == 0) {
      if (p.getSide(TOP) == m_pieces[r-1][c].getSide(BOTTOM)
      || p.getSide(RIGHT) == m_pieces[r][c+1].getSide(LEFT)
      || p.getSide(LEFT) == m_pieces[r][c-1].getSide(RIGHT)) {
          fits = true; // bottom side piece
        }
    } else {
      if (p.getSide(TOP) == m_pieces[r-1][c].getSide(BOTTOM)
      || p.getSide(BOTTOM) == m_pieces[r+1][c].getSide(TOP)
      || p.getSide(RIGHT) == m_pieces[r][c+1].getSide(LEFT)
      || p.getSide(LEFT) == m_pieces[r][c-1].getSide(RIGHT)) {
        fits = true; // middle piece
      }
    }
    if (fits) {
      break;
    }
  }
  if (fits) {
    for (int j = 0; j < cl.getNumPieces(); j++) {
      p = cl.getPiece(j);
      addPiece(p);
    }
    //cout << "added:" << endl;
    u.printBoard(m_pieces,m_rows,m_cols);
    u.printIDs(m_pieces,m_rows,m_cols);
    return true;
  } else {
    return false;
  }
}

void cluster::print() {
  cout << "print:" << endl;
  u.printBoard(m_pieces,m_rows,m_cols);
}
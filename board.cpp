//board.cpp
#include "board.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

board::board() {           // default constructor
}
board::~board() {           // default constructor
  for (int i = 0; i < m_rows; i ++) {
    delete [] m_pieces[i];
  }
  delete [] m_pieces;
  //m_pieces = nullptr;
}
board::board(int rows, int cols) {
  m_rows = rows;           //sets X coordinate to x
  m_cols = cols;           //sets Y coordinate to y
  createBoard(m_rows,m_cols);
  assignPieces();
  //printBoard();
  u.printBoard(m_pieces,rows,cols);
  cluster c;
  c.createCluster(m_rows,m_cols,m_pieces[2][2]);
}
board::board(const board &b) {
}

void board::copy_board(const board &b) {
}


void board::createBoard(int rows, int cols) {
  m_pieces = new piece*[rows];
  for (int i = 0; i < rows; i ++) {
    m_pieces[i] = new piece[cols];
  }
}

void board::assignPieces() {
  int counter = 1;
  for (int i = 0; i < m_rows; i ++) {
    m_pieces[i][0].setSide(LEFT,0);
    m_pieces[i][m_cols-1].setSide(RIGHT,0);
  }
  for (int j = 0; j < m_cols; j ++) {
    m_pieces[0][j].setSide(TOP,0);
    m_pieces[m_rows-1][j].setSide(BOTTOM,0);
  }
  for (int i = 0; i < m_rows; i ++) {
    for (int j = 0; j < m_cols - 1; j ++) {
      m_pieces[i][j].setSide(RIGHT,counter);
      m_pieces[i][j+1].setSide(LEFT,counter);
      counter++;
    }
  }
  for (int i = 0; i < m_rows - 1; i ++) {
    for (int j = 0; j < m_cols; j ++) {
      m_pieces[i][j].setSide(BOTTOM,counter);
      m_pieces[i+1][j].setSide(TOP,counter);
      counter++;
    }
  }
  counter = 0;
  for (int i = 0; i < m_rows; i ++) {
    for (int j = 0; j < m_cols; j ++) {
      m_pieces[i][j].setLocation(i,j);
      m_pieces[i][j].setID(counter);
      counter++;
    }
  }
}

/*void board::printBoard() {
  for (int i = 0; i < m_rows; i ++) {
    for (int j = 0; j < m_cols; j ++) {
      cout << "|  ";
      cout << setw(2) << setfill('0') << m_pieces[i][j].getSide(TOP);
      cout << "  |";
    }
    cout << "\n";
    for (int j = 0; j < m_cols; j ++) {
      cout << "|";
      cout << setw(2) << setfill('0') << m_pieces[i][j].getSide(LEFT);
      cout << "  ";
      cout << setw(2) << setfill('0') << m_pieces[i][j].getSide(RIGHT);
      cout << "|";
    }
    cout << "\n";
    for (int j = 0; j < m_cols; j ++) {
      cout << "|  ";
      cout << setw(2) << setfill('0') << m_pieces[i][j].getSide(BOTTOM);
      cout << "  |";
    }
    cout << "\n";
    for (int j = 0; j < m_cols; j ++) {
      cout << "--------";
    }
    cout << "\n";
  }
}*/
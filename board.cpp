//board.cpp
#include "board.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

/*board::board() {           // default constructor
}*/
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
  u.printBoard(m_pieces,rows,cols);
  u.printIDs(m_pieces,rows,cols);
}
/*board::board(const board &b) {
}*/

/*void board::copy_board(const board &b) {
}*/


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

void board::solve() {
  cluster *currentCluster;
  cluster *compCluster;
  cluster copyCluster;
  int nextPiece;

  vector<cluster*> V;

  for (int i = 0; i < m_rows; i ++) {
    for (int j = 0; j < m_cols; j ++) {
      currentCluster = new cluster();
      currentCluster->createCluster(m_rows,m_cols,m_pieces[i][j]);
      nextPiece = u.randNum(1,100);
      V.push_back(currentCluster);
    }
  }

  int runs = 0;
  int numCompPieces;
  piece compPiece;

  int randNum;
  while (V.size() > 1) {
    randNum = u.randNum(1,V.size()-1);
    copyCluster.copy_cluster(**V.begin());
    compCluster = V.at(randNum);

    numCompPieces = compCluster->getNumPieces();

    if (copyCluster.checkPiece(*compCluster)) {
        delete compCluster;
        V.erase(V.begin()+randNum);
    }

    compCluster = &copyCluster;
    nextPiece = u.randNum(1,100);

    V.push_back(new cluster(copyCluster));
    delete *V.begin();
    V.erase(V.begin());

    if (runs > 550) {
      cout << "nope" << endl;
      break;
    }
    runs++;
  }

  int s = V.size();
  cout << "size: " << s << endl;

  compCluster = V.at(0);
  compCluster->print();

  for (int i = 0; i < (s - 1); i ++) {
    delete &V.back();
    V.pop_back();
  }
  delete *V.begin();
  V.pop_back();
}
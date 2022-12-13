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
  //printBoard();
  u.printBoard(m_pieces,rows,cols);
  u.printIDs(m_pieces,rows,cols);
  /*cluster c;
  c.createCluster(m_rows,m_cols,m_pieces[2][2]);
  c.checkPiece(m_pieces[2][3]);*/
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
  //int numPieces;
  int nextPiece;

  //priority_queue<pair<int,cluster*>> Q;
  //queue<cluster*> Q2;
  vector<cluster*> V;
  //pair<int,string> p;

  // initial runs
  /*for (int i = 0; i < m_rows; i ++) {
    for (int j = 0; j < m_cols; j ++) {
      currentCluster = new cluster();
      currentCluster->createCluster(m_rows,m_cols,m_pieces[i][j]);
      //numPieces = curCluster->getNumPieces();
      nextPiece = u.randNum(1,100);
      Q.push(make_pair(nextPiece,currentCluster));
      //V.push_back(currentCluster);
    }
  }*/

  for (int i = 0; i < m_rows; i ++) {
    for (int j = 0; j < m_cols; j ++) {
      currentCluster = new cluster();
      currentCluster->createCluster(m_rows,m_cols,m_pieces[i][j]);
      //numPieces = curCluster->getNumPieces();
      nextPiece = u.randNum(1,100);
      //Q.push(make_pair(nextPiece,currentCluster));
      V.push_back(currentCluster);
    }
  }

  int runs = 0;
  int numCopyPieces;
  int numCompPieces;
  //piece copyPiece;
  piece compPiece;

  int randNum;
  while (V.size() > 1) {
    //copyCluster.copy_cluster(*Q.top().second);
    randNum = u.randNum(1,V.size()-1);
    copyCluster.copy_cluster(**V.begin());
    compCluster = V.at(randNum);
    //delete Q.top().second;
    //Q.pop();
    //compCluster = Q.top().second;

    /*cout << "copy: " << copyCluster.getNumPieces() << endl;
    copyCluster.print();
    cout << "compare: " << endl;
    compCluster->print();*/

    //numCopyPieces = copyCluster.getNumPieces();
    numCompPieces = compCluster->getNumPieces();

    /*for (int j = 0; j < numCompPieces; j++) {
      compPiece = compCluster->getPiece(j);
      if (copyCluster.checkPiece(compPiece)) {
        delete V.at(randNum);
        V.erase(V.begin()+randNum);
        //delete Q.top().second;
        //Q.pop();
        break;
      }
    }*/

    if (copyCluster.checkPiece(*compCluster)) {
        delete V.at(randNum);
        V.erase(V.begin()+randNum);
    }



    compCluster = &copyCluster;
    nextPiece = u.randNum(1,100);
    //cout << " new nume:L " << nextPiece << endl;
    /*cout << "new: " << endl;
    compCluster->print();*/
    //Q.push(make_pair(nextPiece,new cluster(copyCluster)));
    V.push_back(new cluster(copyCluster));
    //delete V.begin();
    V.erase(V.begin());

    //compCluster = &copyCluster;
    //delete compCluster;
    //compCluster = Q.top().second;
    /*cout << "next21: " << endl;
    compCluster->print();*/
    

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

  /*for (int i = 0; i < s; i ++) {
    delete Q.top().second;
    Q.pop();
  }*/
  for (int i = 0; i < s; i ++) {
    //delete &V.back();
    V.pop_back();
  }
}
//Utilites.cpp
#include "Utilities.h"

int Utilities::randNum(const int min, const int max) {    //RNG
  const int NUM_DIS = 1;                       // number displacement
  return min + rand() % (max - min + NUM_DIS); //Random number in range
}

void Utilities::printBoard(piece ** m_pieces, int m_rows, int m_cols) {
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
}

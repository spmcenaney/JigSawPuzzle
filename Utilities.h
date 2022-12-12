// utilities header
#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <cstdlib>

#include <iomanip>

#include "piece.h"

using namespace std;

class Utilities {
  public:
    // Description: generates random number given bounds
    // Pre: Requires the minimum bound and maximum bounds
    // Post: Returns a random number
    int randNum(const int min, const int max);

    void printBoard(piece ** m_pieces, int m_rows, int m_col);
    void printIDs(piece ** m_pieces, int m_rows, int m_col);
};
#endif

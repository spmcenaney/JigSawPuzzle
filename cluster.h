//cluster.h
#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>

#include "p1.h"
#include "piece.h"
//#include "dungeon.h"
#include "Utilities.h"

class cluster;       //forward declaration of the cluster
//class Utilities;

class cluster {
  public:
    //Purpose: Default constructor for the cluster
    //Pre:
    //Post:
    cluster();
    ~cluster();
    //Purpose: constructor for the cluster
    //Pre:
    //Post:
    //cluster(const cluster &c);
    //Purpose:
    //Pre:
    //Post:
    bool checkPiece(piece p);
    //Purpose: Getter for position
    //Pre: Nothing required
    //Post: Returns position
    //int getSide(int side) {return m_side[side];}
    //Purpose: setter for position
    //Pre: Nothing required
    //Post:
    //void setSide(int side, int value);
    //Purpose: copy cluster
    //Pre:
    //Post: copies variables of cluster to inputted cluster
    //void copy_cluster(const cluster &c);
    void createCluster(int rows, int cols, piece p);

    //Purpose: Getter for position
    //Pre: Nothing required
    //Post: Returns position
    int getNumPieces() {return m_numPieces;}

    //Purpose: Getter for position
    //Pre: Nothing required
    //Post: Returns position
    piece getPiece(int loc) {return m_cluster.at(loc);}

    void print();
  private:

    Utilities u;
    int m_numPieces;

    vector<piece> m_cluster;

    int m_rows;
    int m_cols;

    piece** m_pieces;

    void addPiece(piece p);
};
#endif

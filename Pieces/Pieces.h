#ifndef PIECES_H
#define PIECES_H
#include "BitBoard.h"

using namespace std;

class Pieces {
public:
    //VARS
    BitBoard* pawns;
    BitBoard* rooks;
    BitBoard* knights;
    BitBoard* bishops;
    BitBoard* king;
    BitBoard* queen;

    BitBoard* board;

    vector<BitBoard*> pieceVect;
    //CONSTRUCTOR DESTRUCTOR
    Pieces();
    ~Pieces();

    //FUNCTIONS
    void reset();
    void makeBoard();

    BitBoard* whichPiece(char a, int y);

};



#endif //PIECES_H

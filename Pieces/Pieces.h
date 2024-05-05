#ifndef PIECES_H
#define PIECES_H
#include "BitBoard.h"

using namespace std;

class Pieces {
public:
    //VARS
    BitBoard* whitePawn;
    BitBoard* whiteRooks;
    BitBoard* whiteKnights;
    BitBoard* whiteBishops;
    BitBoard* whiteKing;
    BitBoard* whiteQueen;

    BitBoard* blackPawn;
    BitBoard* blackRooks;
    BitBoard* blackKnights;
    BitBoard* blackBishops;
    BitBoard* blackKing;
    BitBoard* blackQueen;

    BitBoard* whiteBoard;
    BitBoard* blackBoard;
    BitBoard* totalBoard;

    vector<BitBoard*> whiteVect;
    vector<BitBoard*> blackVect;

    //CONSTRUCTOR DESTRUCTOR
    Pieces();
    ~Pieces();

    //SETUP
    void makeWhiteBoard();
    void makeBlackBoard();
    void makeTotalBoard();
    void printBoard();

    //UPKEEP
    void reset();
    void update();

    //BEHAVIORS
    void moveWhite(char from_x, int from_y, char to_x, char to_y);
    void moveBlack(char from_x, int from_y, char to_x, char to_y);
    bool isFree(char from_x, char from_y);
    bitset<64> getPossibleMoves(char from_x, int from_y);
    bitset<64> getBitStringExample(char a, int y);
    //0->Pawn 1->rook 2->bishop 3->knight 4->king 5->queen
    //6->blackPawn 7->blackRook 8->blackBishop 9->blackKnight 10->blackKing 11->blackQueen
    int whichPiece(char a, int y);
    void removeIfThere(char a, int y, int choice);

};



#endif //PIECES_H

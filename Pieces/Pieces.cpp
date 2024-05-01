//
// Created by lando on 5/1/2024.
//
#include "Pieces.h"

using namespace std;

Pieces::Pieces() {
    pawns = new BitBoard;
    pawns->name = "pawn";
    rooks = new BitBoard;
    rooks->name = "rook";
    bishops = new BitBoard;
    bishops->name = "bishop";
    knights = new BitBoard;
    knights->name = "knight";
    king = new BitBoard;
    king->name = "king";
    queen = new BitBoard;
    queen->name = "queen";
    reset();

    pieceVect.push_back(pawns);
    pieceVect.push_back(rooks);
    pieceVect.push_back(bishops);
    pieceVect.push_back(knights);
    pieceVect.push_back(king);
    pieceVect.push_back(queen);


}

Pieces::~Pieces() {
    delete pawns;
}

void Pieces::reset() {
    pawns->setBoardNum(0b0000001000000010000000100000001000000010000000100000001000000010);
    rooks->setBoardNum(0b0000000100000000000000000000000000000000000000000000000000000001);
    knights->setBoardNum(0b0000000000000001000000000000000000000000000000000000000100000000);
    bishops->setBoardNum(0b0000000000000000000000010000000000000000000000010000000000000000);
    queen->setBoardNum(0b0000000000000000000000000000000000000001000000000000000000000000);
    king->setBoardNum(0b0000000000000000000000000000000100000000000000000000000000000000);

}

void Pieces::makeBoard() {
    board = new BitBoard;
    board->setAll(false);

    board->Or(pawns);
    board->Or(knights);
    board->Or(rooks);
    board->Or(bishops);
    board->Or(queen);
    board->Or(king);
}

BitBoard* Pieces::whichPiece(char a, int y) {
    for(int i=0;i<pieceVect.size();i++) {
        if(pieceVect.at(i)->searchByLetters(a,y)==1) {
            return pieceVect.at(i);
        }
    }
}

#include "ChessWindow/Window.h"
#include "Pieces/Pieces.h"
using namespace std;

int main() {
    Pieces piece;
    //0->Pawn 1->rook 2->bishop 3->knight 4->king 5->queen


    piece.whiteQueen->searchByLetters('h',6)=true;
    piece.update();
    piece.getPossibleMoves('h',6);
    //piece.moveWhite('a',1,'a',6);



    return 0;
}

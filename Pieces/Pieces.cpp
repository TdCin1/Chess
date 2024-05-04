//
// Created by lando on 5/1/2024.
//
#include "Pieces.h"

using namespace std;
//CONSTRUCTOR DESTRUCTOR
Pieces::Pieces() {
    whitePawn = new BitBoard;
    whitePawn->name = "whitePawn";
    whiteRooks = new BitBoard;
    whiteRooks->name = "whiteRooks";
    whiteBishops = new BitBoard;
    whiteBishops->name = "whiteBishops";
    whiteKnights = new BitBoard;
    whiteKnights->name = "whiteKnights";
    whiteKing = new BitBoard;
    whiteKing->name = "whiteKing";
    whiteQueen = new BitBoard;
    whiteQueen->name = "whiteQueen";

    blackPawn = new BitBoard;
    blackPawn->name = "blackPawn";
    blackRooks = new BitBoard;
    blackRooks->name = "blackRooks";
    blackBishops = new BitBoard;
    blackBishops->name = "blackBishops";
    blackKnights = new BitBoard;
    blackKnights->name = "blackKnights";
    blackKing = new BitBoard;
    blackKing->name = "blackKing";
    blackQueen = new BitBoard;
    blackQueen->name = "blackQueen";

    reset();

    whiteVect.push_back(whitePawn);
    whiteVect.push_back(whiteRooks);
    whiteVect.push_back(whiteBishops);
    whiteVect.push_back(whiteKnights);
    whiteVect.push_back(whiteKing);
    whiteVect.push_back(whiteQueen);

    blackVect.push_back(blackPawn);
    blackVect.push_back(blackRooks);
    blackVect.push_back(blackBishops);
    blackVect.push_back(blackKnights);
    blackVect.push_back(blackKing);
    blackVect.push_back(blackQueen);



    makeBlackBoard();
    makeWhiteBoard();
    makeTotalBoard();

}

Pieces::~Pieces() {
    delete whitePawn;
    delete whiteRooks;
    delete whiteBishops;
    delete whiteKnights;
    delete whiteKing;
    delete whiteQueen;
    delete whiteBoard;

    delete blackPawn;
    delete blackRooks;
    delete blackBishops;
    delete blackKnights;
    delete blackKing;
    delete blackQueen;
    delete blackBoard;
}

//SET UP
void Pieces::makeWhiteBoard() {
    whiteBoard = new BitBoard;
    whiteBoard->setAll(false);

    whiteBoard->Or(whitePawn);
    whiteBoard->Or(whiteKnights);
    whiteBoard->Or(whiteRooks);
    whiteBoard->Or(whiteBishops);
    whiteBoard->Or(whiteQueen);
    whiteBoard->Or(whiteKing);
}

void Pieces::makeBlackBoard() {
    blackBoard = new BitBoard;
    blackBoard->setAll(false);

    blackBoard->Or(blackPawn);
    blackBoard->Or(blackKnights);
    blackBoard->Or(blackRooks);
    blackBoard->Or(blackBishops);
    blackBoard->Or(blackQueen);
    blackBoard->Or(blackKing);
}

void Pieces::makeTotalBoard() {
    totalBoard = new BitBoard;
    totalBoard->setAll(false);

    totalBoard->Or(whiteBoard);
    totalBoard->Or(blackBoard);
}

void Pieces::printBoard() {
    whiteBoard->printBoardNumbered();
}

//UPKEEP
void Pieces::reset() {
    //WHITE
    //Pawn 0b0000001000000010000000100000001000000010000000100000001000000010
    whitePawn->setBoardNum(0b0000001000000010000000100000001000000010000000100000001000000010);
    //Rook 0b0000000100000000000000000000000000000000000000000000000000000001
    whiteRooks->setBoardNum(0b0000000100000000000000000000000000000000000000000000000000000001);
    //Knight 0b0000000000000001000000000000000000000000000000000000000100000000
    whiteKnights->setBoardNum(0b0000000000000001000000000000000000000000000000000000000100000000);
    //Bishop 0b0000000000000000000000010000000000000000000000010000000000000000
    whiteBishops->setBoardNum(0b0000000000000000000000010000000000000000000000010000000000000000);
    //Queen 0b0000000000000000000000000000000000000001000000000000000000000000
    whiteQueen->setBoardNum(0b0000000000000000000000000000000000000001000000000000000000000000);
    //King 0b0000000000000000000000000000000100000000000000000000000000000000
    whiteKing->setBoardNum(0b0000000000000000000000000000000100000000000000000000000000000000);
    //BLACK
    //Pawn 0b0100000001000000010000000100000001000000010000000100000001000000
    blackPawn->setBoardNum(0b0100000001000000010000000100000001000000010000000100000001000000);
    //Rook 0b1000000000000000000000000000000000000000000000000000000010000000
    blackRooks->setBoardNum(0b1000000000000000000000000000000000000000000000000000000010000000);
    //Knight 0b0000000010000000000000000000000000000000000000001000000000000000
    blackKnights->setBoardNum(0b0000000010000000000000000000000000000000000000001000000000000000);
    //Bishop 0b0000000000000000100000000000000000000000100000000000000000000000
    blackBishops->setBoardNum(0b0000000000000000100000000000000000000000100000000000000000000000);
    //Queen 0b0000000000000000000000000000000010000000000000000000000000000000
    blackQueen->setBoardNum(0b0000000000000000000000000000000010000000000000000000000000000000);
    //King 0b0000000000000000000000001000000000000000000000000000000000000000
    blackKing->setBoardNum(0b0000000000000000000000001000000000000000000000000000000000000000);
}

void Pieces::update() {
    whiteBoard->Or(whitePawn);
    whiteBoard->Or(whiteKnights);
    whiteBoard->Or(whiteRooks);
    whiteBoard->Or(whiteBishops);
    whiteBoard->Or(whiteQueen);
    whiteBoard->Or(whiteKing);

    blackBoard->Or(blackPawn);
    blackBoard->Or(blackKnights);
    blackBoard->Or(blackRooks);
    blackBoard->Or(blackBishops);
    blackBoard->Or(blackQueen);
    blackBoard->Or(blackKing);

    totalBoard->Or(whiteBoard);
    totalBoard->Or(blackBoard);

}

//BEHAVIORS
void Pieces::moveWhite(char from_x, int from_y, char to_x, char to_y) {


}

bitset<64> Pieces::getPossibleMoves(char from_x, int from_y) {
    bitset<64> temp = totalBoard->getBoard() & getBitStringExample(from_x, from_y);
    if (temp.count() == 0) {
        cout << endl << "NO SUCH SQUARE" << endl;
        throw 42;
    }
    //0->Pawn 1->rook 2->bishop 3->knight 4->king 5->queen
    //char to unsigned int a = 97

    int num = whichPiece(from_x, from_y);
    BitBoard result;

    //PAWN
    if (num==0) {
        result.searchByLetters(from_x,from_y+1) = true;
        if(from_y == 2){
            result.searchByLetters(from_x,from_y+2)=true;
        }
        return result.getBoard();
    }
    //ROOK
    else if(num==1){
        //ROWS AHEAD
        for(int i = from_y+1;i < 9;i++){
            if(isFree(from_x,i)){
                result.searchByLetters(from_x,i) = true;
            }
            else{
                break;
            }
        }
        //ROWS BEHIND
        for(int i = from_y-1;i >-1;i--){
            if(isFree(from_x,i)){
                result.searchByLetters(from_x,i) = true;
            }
            else{
                break;
            }
        }

        //COLS AHEAD
        unsigned int cols = (unsigned int)from_x;
        for(unsigned int i = cols+1;i<105;i++){
            if(isFree((unsigned char)i,from_y)){
                result.searchByLetters((unsigned char)i,from_y) = true;
            }
            else{
                break;
            }
        }
        //COLS BEHIND
        for(unsigned int i = cols-1;i>96;i--){
            if(isFree((unsigned char)i,from_y)){
                result.searchByLetters((unsigned char)i,from_y) = true;
            }
            else{
                break;
            }
        }
        return result.getBoard();
    }
    //BISHOP
    else if(num==2){
        //BOTTOM LEFT
        int loops=0;
        unsigned int cols = (unsigned int)from_x;
        for(unsigned int i = cols+1;i<105;i++){
            loops++;
            if(isFree((unsigned char)i,from_y-loops)){
                result.searchByLetters((unsigned char)i,from_y-loops) = true;
            }
            else{
                break;
            }
        }
        //BOTTOM RIGHT
        loops = 0;
        for(unsigned int i = cols-1;i>96;i--){
            loops++;
            if(isFree((unsigned char)i,from_y-loops)){
                result.searchByLetters((unsigned char)i,from_y-loops) = true;
            }
            else{
                break;
            }
        }
        //TOP LEFT
        loops = 0;
        for(unsigned int i = cols-1;i>96;i--){
            loops++;
            if(isFree((unsigned char)i,from_y+loops)){
                result.searchByLetters((unsigned char)i,from_y+loops) = true;
            }
            else{
                break;
            }
        }
        //TOP LEFT
        loops = 0;
        for(unsigned int i = cols+1;i<105;i++){
            loops++;
            if(isFree((unsigned char)i,from_y+loops)){
                result.searchByLetters((unsigned char)i,from_y+loops) = true;
            }
            else{
                break;
            }
        }

        //RETURN
        return result.getBoard();
    }
    //KNIGHT
    else if(num==3){
        unsigned int cols = (unsigned int)from_x;
        char x;
        int y;

        //TOP LEFT height
        x=cols-1;
        y=from_y+2;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }

        //TOP LEFT wide
        x=cols-2;
        y=from_y+1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }

        //BOTTOM LEFT height
        x=cols-1;
        y=from_y-2;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }

        //BOTTOM LEFT wide
        x=cols-2;
        y=from_y-1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }

        //TOP RIGHT height
        x=cols+1;
        y=from_y+2;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        //TOP RIGHT wide
        x=cols+2;
        y=from_y+1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        //BOTTOM RIGHT height
        x=cols+1;
        y=from_y-2;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        //BOTTOM RIGHT wide
        x=cols+2;
        y=from_y-1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }

        //RETURN
        return result.getBoard();
    }
    //KING
    //NEED TO ADD CASTLING
    else if(num==4){
        unsigned int cols = (unsigned int)from_x;
        char x;
        int y;

        //Circle around king
        x=cols-1;
        y=from_y;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        x=cols-1;
        y=from_y+1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        x=cols;
        y=from_y+1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        x=cols+1;
        y=from_y+1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        x=cols+1;
        y=from_y;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        x=cols+1;
        y=from_y-1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        x=cols;
        y=from_y-1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        x=cols-1;
        y=from_y-1;
        if((104>=cols && cols>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }

        //RETURN
        return result.getBoard();
    }
    //QUEEN
    else if(num==5){
        //Rook movements
        //ROWS AHEAD
        for(int i = from_y+1;i < 9;i++){
            if(isFree(from_x,i)){
                result.searchByLetters(from_x,i) = true;
            }
            else{
                break;
            }
        }
        //ROWS BEHIND
        for(int i = from_y-1;i >-1;i--){
            if(isFree(from_x,i)){
                result.searchByLetters(from_x,i) = true;
            }
            else{
                break;
            }
        }

        //COLS AHEAD
        unsigned int cols = (unsigned int)from_x;
        for(unsigned int i = cols+1;i<105;i++){
            if(isFree((unsigned char)i,from_y)){
                result.searchByLetters((unsigned char)i,from_y) = true;
            }
            else{
                break;
            }
        }
        //COLS BEHIND
        for(unsigned int i = cols-1;i>96;i--){
            if(isFree((unsigned char)i,from_y)){
                result.searchByLetters((unsigned char)i,from_y) = true;
            }
            else{
                break;
            }
        }
        //Bishop movements
        //BOTTOM LEFT

        int loops=0;
        cols = (unsigned int)from_x;
        for(unsigned int i = cols+1;i<105;i++){
            loops++;
            if(isFree((unsigned char)i,from_y-loops)){
                result.searchByLetters((unsigned char)i,from_y-loops) = true;
            }
            else{
                break;
            }
        }
        //BOTTOM RIGHT
        loops = 0;
        for(unsigned int i = cols-1;i>96;i--){
            loops++;
            if(isFree((unsigned char)i,from_y-loops)){
                result.searchByLetters((unsigned char)i,from_y-loops) = true;
            }
            else{
                break;
            }
        }
        //TOP LEFT
        loops = 0;
        for(unsigned int i = cols-1;i>96;i--){
            loops++;
            if(isFree((unsigned char)i,from_y+loops)){
                result.searchByLetters((unsigned char)i,from_y+loops) = true;
            }
            else{
                break;
            }
        }
        //TOP LEFT
        loops = 0;
        for(unsigned int i = cols+1;i<105;i++){
            loops++;
            if(isFree((unsigned char)i,from_y+loops)){
                result.searchByLetters((unsigned char)i,from_y+loops) = true;
            }
            else{
                break;
            }
        }

        //RETURN
        result.printBoardNumbered();
        return result.getBoard();

    }
    //BLACK PAWN
    else if(num==6){
        result.searchByLetters(from_x,from_y-1) = true;
        if(from_y == 7){
            result.searchByLetters(from_x,from_y-2)=true;
        }
        result.printBoardNumbered();
        return result.getBoard();
    }

}

void Pieces::moveBlack(char from_x, int from_y, char to_x, char to_y) {

}

bool Pieces::isFree(char from_x, char from_y) {
    if(!totalBoard->searchByLetters(from_x,from_y)==1){
        return true;
    }
    return false;
}

bitset<64> Pieces::getBitStringExample(char a, int y) {
    BitBoard temp;
    temp.setAll(false);
    temp.searchByLetters(a,y)=true;
    return temp.getBoard();

}

int Pieces::whichPiece(char a, int y) {
    for(int i=0;i<whiteVect.size();i++) {
        if(whiteVect.at(i)->searchByLetters(a,y)==1) {
            //0->Pawn 1->rook 2->bishop 3->knight 4->king 5->queen
            return i;
        }
    }
    for(int i=0;i<blackVect.size();i++) {
        if(blackVect.at(i)->searchByLetters(a,y)==1) {
            if(i==0){
                return 6;
            }
            //0->Pawn 1->rook 2->bishop 3->knight 4->king 5->queen
            return i;
        }
    }
    return -1;
}

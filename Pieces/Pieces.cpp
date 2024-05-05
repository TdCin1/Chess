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
    whiteBoard->setAll(false);
    blackBoard->setAll(false);
    totalBoard->setAll(false);

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
    //0->Pawn 1->rook 2->bishop 3->knight 4->king 5->queen
    //6->blackPawn 7->blackRook 8->blackBishop 9->blackKnight 10->blackKing 11->blackQueen
    int num = whichPiece(from_x,from_y);
    cout<<"num: "<<num<<endl;

    bitset<64> temp = getPossibleMoves(from_x,from_y);
    temp = getBitStringExample(to_x,to_y) & temp;
    if (temp.count() == 0) {
        cout << endl << "NO SUCH SQUARE" << endl;
        throw 42;
    }

    else{
        //THE MOVE IS VALID
        //White Pawn
        //NEED TO ADD CORRECT CAPTURES
        if(num==0){
            whitePawn->searchByLetters(from_x,from_y)=false;
            removeIfThere(from_x,from_y,0);
            whitePawn->searchByLetters(to_x,to_y)=true;
        }
        else if(num==1){
            whiteRooks->searchByLetters(from_x,from_y)=false;
            removeIfThere(from_x,from_y,1);
            whiteRooks->searchByLetters(to_x,to_y)=true;
        }
        else if(num ==2){

        }
    }

    update();
}

void Pieces::moveBlack(char from_x, int from_y, char to_x, char to_y) {

}

void Pieces::removeIfThere(char a, int y, int choice) {
    //0->Pawn 1->rook 2->bishop 3->knight 4->king 5->queen
    //6->blackPawn 7->blackRook 8->blackBishop 9->blackKnight 10->blackKing 11->blackQueen
    if(choice==-1){
        return;
    }
    else if(choice==0){
        whitePawn->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==1){
        whiteRooks->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==2){
        whiteBishops->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==3){
        whiteKnights->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==4){
        whiteKing->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==5){
        whiteQueen->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==6){
        blackPawn->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==7){
        blackRooks->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==8){
        blackBishops->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==9){
        blackKnights->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==10){
        blackKing->searchByLetters(a,y)=false;
        return;
    }
    else if(choice==11){
        blackQueen->searchByLetters(a,y)=false;
        return;
    }

}

bitset<64> Pieces::getPossibleMoves(char from_x, int from_y) {
    bitset<64> temp = totalBoard->getBoard() & getBitStringExample(from_x, from_y);
    if (temp.count() == 0) {
        cout << endl << "NO SUCH SQUARE" << endl;
        throw 42;
    }
    //0->Pawn 1->rook 2->bishop 3->knight 4->king 5->queen
    //6->blackPawn 7->blackRook 8->blackBishop 9->blackKnight 10->blackKing 11->blackQueen
    //char to unsigned int a = 97

    int num = whichPiece(from_x, from_y);
    bool isWhite=false;
    if(6>num){
        isWhite=true;
    }
    BitBoard result;

    //PAWN
    //NEED TO ADD CAPTURES
    if (num==0) {
        if(isFree(from_x,from_y+1)){
            result.searchByLetters(from_x,from_y+1) = true;
        }
        if(isFree(from_x,from_y+1)){
            if(from_y == 2){
                result.searchByLetters(from_x,from_y+2)=true;
            }
        }
        return result.getBoard();
    }
    //ROOK
    else if(num==1||num==7){
        //ROWS AHEAD
        for(int i = from_y+1;i < 9;i++){
            if(isFree(from_x,i)){
                result.searchByLetters(from_x,i) = true;
            }
            else{
                int pieceAhead = whichPiece(from_x,i);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters(from_x,i) = true;
                }

                break;
            }
        }
        //ROWS BEHIND
        for(int i = from_y-1;i >0;i--){
            if(isFree(from_x,i)){
                result.searchByLetters(from_x,i) = true;
            }
            else{
                int pieceAhead = whichPiece(from_x,i);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters(from_x,i) = true;
                }

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
                int pieceAhead = whichPiece((unsigned char)i,from_y);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y) = true;
                }

                break;
            }
        }
        //COLS BEHIND
        for(unsigned int i = cols-1;i>96;i--){
            if(isFree((unsigned char)i,from_y)){
                result.searchByLetters((unsigned char)i,from_y) = true;
            }
            else{
                int pieceAhead = whichPiece((unsigned char)i,from_y);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y) = true;
                }

                break;
            }
        }
        return result.getBoard();
    }
    //BISHOP
    else if(num==2||num==8){
        //BOTTOM LEFT
        int loops=0;
        unsigned int cols = (unsigned int)from_x;
        for(unsigned int i = cols+1;i<105;i++){
            loops++;
            if(isFree((unsigned char)i,from_y-loops)){
                result.searchByLetters((unsigned char)i,from_y-loops) = true;
            }
            else{
                int pieceAhead = whichPiece((unsigned char)i,from_y-loops);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y-loops) = true;
                }

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
                int pieceAhead = whichPiece((unsigned char)i,from_y-loops);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y-loops) = true;
                }

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
                int pieceAhead = whichPiece((unsigned char)i,from_y+loops);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y+loops) = true;
                }

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
                int pieceAhead = whichPiece((unsigned char)i,from_y+loops);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y+loops) = true;
                }

                break;
            }
        }

        //RETURN
        return result.getBoard();
    }
    //KNIGHT
    else if(num==3||num==9){
        unsigned int cols = (unsigned int)from_x;
        char x;
        int y;

        //TOP LEFT height
        x=cols-1;
        y=from_y+2;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }

        //TOP LEFT wide
        x=cols-2;
        y=from_y+1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }

        //BOTTOM LEFT height
        x=cols-1;
        y=from_y-2;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }

        //BOTTOM LEFT wide
        x=cols-2;
        y=from_y-1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }

        //TOP RIGHT height
        x=cols+1;
        y=from_y+2;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        //TOP RIGHT wide
        x=cols+2;
        y=from_y+1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        //BOTTOM RIGHT height
        x=cols+1;
        y=from_y-2;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        //BOTTOM RIGHT wide
        x=cols+2;
        y=from_y-1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        //RETURN
        return result.getBoard();
    }
    //KING
    //NEED TO ADD CASTLING
    else if(num==4||num==10){
        unsigned int cols = (unsigned int)from_x;
        char x;
        int y;


        //Circle around king
        x=cols-1;
        y=from_y;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
        }
        x=cols-1;
        y=from_y+1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        x=cols;
        y=from_y+1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        x=cols+1;
        y=from_y+1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        x=cols+1;
        y=from_y;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        x=cols+1;
        y=from_y-1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        x=cols;
        y=from_y-1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }
        x=cols-1;
        y=from_y-1;
        if((104>=x && x>=97)&&(8>=y && y>=1)){
            if(isFree(x,y)){
                result.searchByLetters((unsigned char)x,y) = true;
            }
            else{
                int pieceAhead = whichPiece(x,y);
                if(!((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite))){
                    result.searchByLetters((unsigned char)x,y) = true;
                }
            }
        }

        //RETURN
        return result.getBoard();
    }
    //QUEEN
    else if(num==5||num==11) {
        //ROOK
        //ROWS AHEAD
        for(int i = from_y+1;i < 9;i++){
            if(isFree(from_x,i)){
                result.searchByLetters(from_x,i) = true;
            }
            else{
                int pieceAhead = whichPiece(from_x,i);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters(from_x,i) = true;
                }

                break;
            }
        }
        //ROWS BEHIND
        for(int i = from_y-1;i >0;i--){
            if(isFree(from_x,i)){
                result.searchByLetters(from_x,i) = true;
            }
            else{
                int pieceAhead = whichPiece(from_x,i);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters(from_x,i) = true;
                }

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
                int pieceAhead = whichPiece((unsigned char)i,from_y);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y) = true;
                }

                break;
            }
        }
        //COLS BEHIND
        for(unsigned int i = cols-1;i>96;i--){
            if(isFree((unsigned char)i,from_y)){
                result.searchByLetters((unsigned char)i,from_y) = true;
            }
            else{
                int pieceAhead = whichPiece((unsigned char)i,from_y);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y) = true;
                }

                break;
            }
        }
        //BISHOP
        //BOTTOM LEFT
        int loops=0;
        cols = (unsigned int)from_x;
        for(unsigned int i = cols+1;i<105;i++){
            loops++;
            if(isFree((unsigned char)i,from_y-loops)){
                result.searchByLetters((unsigned char)i,from_y-loops) = true;
            }
            else{
                int pieceAhead = whichPiece((unsigned char)i,from_y-loops);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y-loops) = true;
                }

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
                int pieceAhead = whichPiece((unsigned char)i,from_y-loops);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y-loops) = true;
                }

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
                int pieceAhead = whichPiece((unsigned char)i,from_y+loops);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y+loops) = true;
                }

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
                int pieceAhead = whichPiece((unsigned char)i,from_y+loops);
                if(pieceAhead==-1){
                    break;
                }
                else if((6>pieceAhead && isWhite)||(5<pieceAhead && !isWhite)){
                    break;
                }
                else{
                    result.searchByLetters((unsigned char)i,from_y+loops) = true;
                }

                break;
            }
        }

        //RETURN
        return result.getBoard();
    }
    //BLACK PAWN
    else if(num==6){
        if(isFree(from_x,from_y-1)){
            result.searchByLetters(from_x,from_y-1) = true;
        }
        if(isFree(from_x,from_y-1)){
            if(from_y == 7){
                result.searchByLetters(from_x,from_y-2)=true;
            }
        }
        return result.getBoard();
    }

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
            //0->Pawn 1->rook 2->bishop 3->knight 4->king 5->queen
            return i+6;
        }
    }
    return -1;
}

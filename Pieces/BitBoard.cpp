//
// Created by lando on 4/30/2024.
//

#include "BitBoard.h"

void BitBoard::printBoardRaw() {
    cout<<board;
}
void BitBoard::printBoard() {
    for(int i=7;i>-1;i--) {
        for(int j=0; j<8 ;j++) {
            //cout<<"i: "<< i << " j: "<<j<<endl;
            cout<<search(i,j)<<"  ";
        }
        cout<<endl;
    }
}
void BitBoard::printBoardNumbered() {
    for(int i=7;i>-1;i--) {
        cout<<i+1<<":  ";

        for(int j=0; j<8 ;j++) {
            //cout<<"i: "<< i << " j: "<<j<<endl;
            cout<<search(i,j)<<"  ";
        }
        cout<<endl;
    }
    cout<<"    ";
    for(int i =0;i<8;i++) {
        cout<<(unsigned char)(i+65)<<"  ";
    }
    cout<<endl;
}

bitset<64> BitBoard::getBoard() {
    return board;
}

void BitBoard::Or(BitBoard* set) {
    board = board | set->getBoard();
}

void BitBoard::And(BitBoard* set) {
    board = board & set->getBoard();
}

void BitBoard::setBoardNum(unsigned long long num) {
    board = num;
}

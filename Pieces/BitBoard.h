#ifndef BITBOARD_H
#define BITBOARD_H
#include<bitset>
#include<cassert>
#include<iostream>
#include <vector>

using namespace std;

class BitBoard {
private:
    std::bitset<64> board;
public:
    auto search(int x, int y){
        assert(0<=x && x<=7);
        assert(0<=y && y<=7);
        return board[8*y+x];
    }
    auto searchByLetters(char a, int y){
        int x = (unsigned int)a-97;
        assert(0<=x && x<=7);
        assert(1<=y && y<=8);
        y--;
        return board[8*x+y];
    }
    void setAll(bool val){
        if(val)
            board.set();   //All bits on
        else
            board.reset(); //All bits off
    }
    //VAR
    string name;

    //PRINTS
    void printBoardRaw();
    void printBoard();
    void printBoardNumbered();

    //GETTERS
    bitset<64> getBoard();
    void Or(BitBoard* set);
    void And(BitBoard* set);
    void setBoardNum(unsigned long long num);

};



#endif //BITBOARD_H

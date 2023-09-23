#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>
#include <stdlib.h>
#include "Common.hpp"

/*
BitBoard
  10   9   8   7   6   5   4   3   2   1   0 Column/Row
_____________________________________________
| 10|  9|  8|  7|  6|  5|  4|  3|  2|  1|  0|  0
| 21| 20| 19| 18| 17| 16| 15| 14| 13| 12| 11|  1
| 32| 31| 30| 29| 28| 27| 26| 25| 24| 23| 22|  2
| 43| 42| 41| 40| 39| 38| 37| 36| 35| 34| 33|  3
| 54| 53| 52| 51| 50| 49| 48| 47| 46| 45| 44|  4
| 65| 64| 63| 62| 61| 60| 59| 58| 57| 56| 55|  5
| 76| 75| 74| 73| 72| 71| 70| 69| 68| 67| 66|  6
| 87| 86| 85| 84| 83| 82| 81| 80| 79| 78| 77|  7
| 98| 97| 96| 95| 94| 93| 92| 91| 90| 89| 88|  8
|109|108|107|106|105|104|103|102|101|100| 99|  9
|120|119|118|117|116|115|114|113|112|111|110| 10
---------------------------------------------
the board is located in rows 1 to 9 and columns 1 to 9
*/

#define LENGTH_OF_BOARD 121
#define LENGTH_OF_FRAME 11
#define LENGTH_OF_EDGE 9
#define STRING_OF_FRAME "11111111111" \
                        "10000000001" \
                        "10000000001" \
                        "10000000001" \
                        "10000000001" \
                        "10000000001" \
                        "10000000001" \
                        "10000000001" \
                        "10000000001" \
                        "10000000001" \
                        "11111111111"
#define STRING_OF_PRO_ZONE_BLACK "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "01111111110" \
                                 "01111111110" \
                                 "01111111110" \
                                 "00000000000"
#define STRING_OF_PRO_ZONE_WHITE "00000000000" \
                                 "01111111110" \
                                 "01111111110" \
                                 "01111111110" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000"
#define STRING_OF_LAST1_ZONE_BLACK "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "01111111110" \
                                   "00000000000"
#define STRING_OF_LAST1_ZONE_WHITE "00000000000" \
                                   "01111111110" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000"
#define STRING_OF_LAST2_ZONE_BLACK "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "01111111110" \
                                   "01111111110" \
                                   "00000000000"
#define STRING_OF_LAST2_ZONE_WHITE "00000000000" \
                                   "01111111110" \
                                   "01111111110" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000" \
                                   "00000000000"

class BitBoard
{
private:
public:
    std::bitset<LENGTH_OF_BOARD> board;
    BitBoard(){
        board = std::bitset<LENGTH_OF_BOARD>(0);
    }
    BitBoard(const BitBoard& bitBoard){
        board = bitBoard.board;
    }
    BitBoard(const std::bitset<LENGTH_OF_BOARD> bitset){
        board = bitset;
    }
    BitBoard(const uint64_t value){
        board = std::bitset<LENGTH_OF_BOARD>(value);
    }
    BitBoard(const char* value){
        board = std::bitset<LENGTH_OF_BOARD>(value);
    }
    void to_ullongs(uint64_t* result){
        std::bitset<LENGTH_OF_BOARD> bn1 = board >> BIT_NUMBER_ULL;
        std::bitset<LENGTH_OF_BOARD> bn2 = (bn1 << BIT_NUMBER_ULL) ^ board;
        result[0] = bn1.to_ullong();
        result[1] = bn2.to_ullong();
    }
    int getTrues(int** result){
        int trueCount = board.count();
        *result = new int[trueCount];
        int index = 0;
        for (int i = 0; i < board.size(); i++){
            if (board.test(i)){
                (*result)[index] = i;
                index++;
            }
        }
        return trueCount;
    }

    BitBoard operator &(BitBoard bitBoard){
        return (*this).board & bitBoard.board;
    }
    BitBoard operator &(std::bitset<LENGTH_OF_BOARD> board){
        return (*this).board & board;
    }

    BitBoard operator |(BitBoard bitBoard){
        return (*this).board | bitBoard.board;
    }
    BitBoard operator |(std::bitset<LENGTH_OF_BOARD> board){
        return (*this).board | board;
    }

    BitBoard operator <<(int num){
        return (*this).board << num;
    }
    BitBoard operator >>(int num){
        return (*this).board >> num;
    }

    static BitBoard generateColumns(int* columnNo, int columnCount){
        BitBoard bitBoard = BitBoard();
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < columnCount; j++){
                bitBoard.board.set(columnNo[j]);
            }
            bitBoard.board <<= 11;
        }
        return bitBoard;
    }

    static BitBoard generateColumn(int columnNo){
        BitBoard bitBoard = BitBoard();
        for (int i = 0; i < 9; i++){
            bitBoard.board.set(columnNo);
            bitBoard.board <<= 11;
        }
        return bitBoard;
    }
};
#endif
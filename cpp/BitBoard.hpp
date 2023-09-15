#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>

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
    BitBoard(const uint64_t value){
        board = std::bitset<LENGTH_OF_BOARD>(value);
    }
    BitBoard(const char* value){
        board = std::bitset<LENGTH_OF_BOARD>(value);
    }
    void to_ullongs(uint64_t* result){
        std::bitset<LENGTH_OF_BOARD> bn1 = board >> 64;
        std::bitset<LENGTH_OF_BOARD> bn2 = (bn1 << 64) ^ board;
        result[0] = bn1.to_ullong();
        result[1] = bn2.to_ullong();
    }
};
#endif
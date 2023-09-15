#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>

#define LENGTH_OF_FRAME 11
#define LENGTH_OF_EDGE 9
#define STRING_OF_FRAME "11111111111" "10000000001"\
                        "10000000001" "10000000001"\
                        "10000000001" "10000000001"\
                        "10000000001" "10000000001"\
                        "10000000001" "10000000001"\
                        "11111111111"

class BitBoard
{
private:
public:
    std::bitset<121> board;
    BitBoard(){
        board = std::bitset<121>(0);
    }
    BitBoard(const BitBoard& bitBoard){
        board = bitBoard.board;
    }
    BitBoard(const uint64_t value){
        board = std::bitset<121>(value);
    }
    BitBoard(const char* value){
        board = std::bitset<121>(value);
    }
    void to_ullongs(uint64_t* result){
        std::bitset<121> bn1 = board >> 64;
        std::bitset<121> bn2 = (bn1 << 64) ^ board;
        result[0] = bn1.to_ullong();
        result[1] = bn2.to_ullong();
    }
};
#endif
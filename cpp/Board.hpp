#ifndef BOARD_HPP
#define BOARD_HPP
#include "BitBoard.hpp"
#include "PieceType.hpp"

class Board
{
private:
public:
    BitBoard hasPiece;
    BitBoard playerPossession[2];
    const BitBoard isFrame = BitBoard(STRING_OF_FRAME);
    BitBoard hasSpecificPiece[PieceTypeNumber];
};
#endif
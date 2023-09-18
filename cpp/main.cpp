#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>
#include "BitBoard.hpp"
#include "Board.hpp"

int main() {
    Board board = Board();
    int* arrayTrueIndex;
    int trueCount = board.hasPiece.getTrues(&arrayTrueIndex);
    for (int i = 0; i < trueCount; i++){
        printf("%d,", arrayTrueIndex[i]);
    }
    printf("\n");
    std::cout << "frame   : " << board.isFrame.board << std::endl;
    std::cout << "hasPiece: " << board.hasPiece.board << std::endl;
    std::cout << "Black   : " << board.playerPossession[(uint64_t)ColorType::Black].board << std::endl;
    std::cout << "White   : " << board.playerPossession[(uint64_t)ColorType::White].board << std::endl;
    std::cout << "None    : " << board.hasSpecificPiece[(uint64_t)PieceType::None].board << std::endl;
    std::cout << "King    : " << board.hasSpecificPiece[(uint64_t)PieceType::King].board << std::endl;
    std::cout << "Gold    : " << board.hasSpecificPiece[(uint64_t)PieceType::Gold].board << std::endl;
    std::cout << "Rook    : " << board.hasSpecificPiece[(uint64_t)PieceType::Rook].board << std::endl;
    std::cout << "Bichop  : " << board.hasSpecificPiece[(uint64_t)PieceType::Bichop].board << std::endl;
    std::cout << "Silver  : " << board.hasSpecificPiece[(uint64_t)PieceType::Silver].board << std::endl;
    std::cout << "Knight  : " << board.hasSpecificPiece[(uint64_t)PieceType::Knight].board << std::endl;
    std::cout << "Lance   : " << board.hasSpecificPiece[(uint64_t)PieceType::Lance].board << std::endl;
    std::cout << "Pawn    : " << board.hasSpecificPiece[(uint64_t)PieceType::Pawn].board << std::endl;
    
    // uint64_t num = 4096;
    // BitBoard bitBoard = BitBoard(num);
    // BitBoard bitFrame = BitBoard(STRING_OF_FRAME);
    // BitBoard bitMovable = BitBoard();
    // std::bitset<4> isInBoard(15);
    // for (int i = 1; i < LENGTH_OF_EDGE; i++)
    // {
    //     if (isInBoard.none())
    //     {
    //         break;
    //     }
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if (isInBoard[j])
    //         {
    //             int v = j == 0 || j == 3 ? - 1 * i : i;
    //             int h = j > 1 ? - 1 * i : i;
    //             int shiftNumber = LENGTH_OF_FRAME * h + v;
    //             std::bitset<121> bn1 = shiftNumber > 0 ? bitBoard.board << shiftNumber : bitBoard.board >> abs(shiftNumber);
    //             if ((bitFrame.board & bn1).any())
    //             {
    //                 isInBoard[j] = 0;
    //             }
    //             else
    //             {
    //                 bitMovable.board = bitMovable.board | bn1;
    //             }
    //         }
    //     }
    // }
    // std::cout << "bf   : " << bitFrame.board << std::endl;
    // std::cout << "b    : " << bitBoard.board << std::endl;
    // std::cout << "bn   : " << bitMovable.board << std::endl;
    // uint64_t uuln[2];
    // bitMovable.to_ullongs(uuln);
    // std::cout << "uuln1  : " << uuln[0] << std::endl;
    // std::cout << "uuln2  : " << uuln[1] << std::endl;
}
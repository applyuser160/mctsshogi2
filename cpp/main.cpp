#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>
#include "BitBoard.hpp"

int main() {
    uint64_t num = 4096;
    BitBoard bitBoard = BitBoard(num);
    BitBoard bitFrame = BitBoard(STRING_OF_FRAME);
    BitBoard bitMovable = BitBoard();
    std::bitset<4> isInBoard(15);
    for (int i = 1; i < LENGTH_OF_EDGE; i++)
    {
        if (isInBoard.none())
        {
            break;
        }
        for (int j = 0; j < 4; j++)
        {
            if (isInBoard[j])
            {
                int v = j == 0 || j == 3 ? - 1 * i : i;
                int h = j > 1 ? - 1 * i : i;
                int shiftNumber = LENGTH_OF_FRAME * h + v;
                std::bitset<121> bn1 = shiftNumber > 0 ? bitBoard.board << shiftNumber : bitBoard.board >> abs(shiftNumber);
                if ((bitFrame.board & bn1).any())
                {
                    isInBoard[j] = 0;
                }
                else
                {
                    bitMovable.board = bitMovable.board | bn1;
                }
            }
        }
    }
    std::cout << "bf   : " << bitFrame.board << std::endl;
    std::cout << "b    : " << bitBoard.board << std::endl;
    std::cout << "bn   : " << bitMovable.board << std::endl;
    uint64_t uuln[2];
    bitMovable.to_ullongs(uuln);
    std::cout << "uuln1  : " << uuln[0] << std::endl;
    std::cout << "uuln2  : " << uuln[1] << std::endl;
}
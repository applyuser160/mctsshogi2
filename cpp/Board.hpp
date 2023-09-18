#ifndef BOARD_HPP
#define BOARD_HPP
#include "BitBoard.hpp"
#include "PieceType.hpp"
#include "ColorType.hpp"

#define STRING_OF_START_PIECE "00000000000" \
                              "01111111110" \
                              "00100000100" \
                              "01111111110" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "01111111110" \
                              "00100000100" \
                              "01111111110" \
                              "00000000000"
#define STRING_OF_START_BLACK "00000000000" \
                              "01111111110" \
                              "00100000100" \
                              "01111111110" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000"
#define STRING_OF_START_WHITE "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "01111111110" \
                              "00100000100" \
                              "01111111110" \
                              "00000000000"
#define STRING_OF_START_NONE  "00000000000" \
                              "00000000000" \
                              "01011111010" \
                              "00000000000" \
                              "01111111110" \
                              "01111111110" \
                              "01111111110" \
                              "00000000000" \
                              "01011111010" \
                              "00000000000" \
                              "00000000000"
#define STRING_OF_START_KING  "00000000000" \
                              "00000100000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000100000" \
                              "00000000000"
#define STRING_OF_START_GOLD  "00000000000" \
                              "00001010000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00001010000" \
                              "00000000000"
#define STRING_OF_START_ROOK "00000000000" \
                               "00000000000" \
                               "00000000100" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00100000000" \
                               "00000000000" \
                               "00000000000"
#define STRING_OF_START_BICHOP  "00000000000" \
                              "00000000000" \
                              "00100000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000100" \
                              "00000000000" \
                              "00000000000"
#define STRING_OF_START_SILVER "00000000000" \
                               "00010001000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00010001000" \
                               "00000000000"
#define STRING_OF_START_KNIGHT "00000000000" \
                               "00100000100" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00100000100" \
                               "00000000000"
#define STRING_OF_START_LANCE "00000000000" \
                              "01000000010" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "01000000010" \
                              "00000000000"
#define STRING_OF_START_PAWN "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "01111111110" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "01111111110" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000"
#define STRING_OF_START_DRAGON "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000"
#define STRING_OF_START_HORSE "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000"
#define STRING_OF_START_PROSILVER "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000"
#define STRING_OF_START_PROKNIGHT "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000"
#define STRING_OF_START_PROLANCE "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000"
#define STRING_OF_START_PROPAWN "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000"
#define STRING_OF_PRO_ZONE "00000000000" \
                           "01111111110" \
                           "01111111110" \
                           "01111111110" \
                           "00000000000" \
                           "00000000000" \
                           "00000000000" \
                           "01111111110" \
                           "01111111110" \
                           "01111111110" \
                           "00000000000"
#define STRING_OF_LAST1_ZONE "00000000000" \
                             "01111111110" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "01111111110" \
                             "00000000000"
#define STRING_OF_LAST2_ZONE "00000000000" \
                             "01111111110" \
                             "01111111110" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "01111111110" \
                             "01111111110" \
                             "00000000000"

class Board
{
private:
public:
    BitBoard hasPiece;
    BitBoard playerPossession[(uint64_t)ColorType::ColorNumber];
    BitBoard isFrame = BitBoard(STRING_OF_FRAME);
    BitBoard ablePro = BitBoard(STRING_OF_PRO_ZONE);
    BitBoard lastOne = BitBoard(STRING_OF_LAST1_ZONE);
    BitBoard lastTwo = BitBoard(STRING_OF_LAST2_ZONE);
    BitBoard hasSpecificPiece[(uint64_t)PieceType::PieceTypeNumber];
    Board(){
        hasPiece = BitBoard(STRING_OF_START_PIECE);
        playerPossession[(uint64_t)ColorType::Black] = BitBoard(STRING_OF_START_BLACK);
        playerPossession[(uint64_t)ColorType::White] = BitBoard(STRING_OF_START_WHITE);
        hasSpecificPiece[(uint64_t)PieceType::None] = BitBoard(STRING_OF_START_NONE);
        hasSpecificPiece[(uint64_t)PieceType::King] = BitBoard(STRING_OF_START_KING);
        hasSpecificPiece[(uint64_t)PieceType::Gold] = BitBoard(STRING_OF_START_GOLD);
        hasSpecificPiece[(uint64_t)PieceType::Rook] = BitBoard(STRING_OF_START_ROOK);
        hasSpecificPiece[(uint64_t)PieceType::Bichop] = BitBoard(STRING_OF_START_BICHOP);
        hasSpecificPiece[(uint64_t)PieceType::Silver] = BitBoard(STRING_OF_START_SILVER);
        hasSpecificPiece[(uint64_t)PieceType::Knight] = BitBoard(STRING_OF_START_KNIGHT);
        hasSpecificPiece[(uint64_t)PieceType::Lance] = BitBoard(STRING_OF_START_LANCE);
        hasSpecificPiece[(uint64_t)PieceType::Pawn] = BitBoard(STRING_OF_START_PAWN);
        hasSpecificPiece[(uint64_t)PieceType::Dragon] = BitBoard(STRING_OF_START_DRAGON);
        hasSpecificPiece[(uint64_t)PieceType::Horse] = BitBoard(STRING_OF_START_HORSE);
        hasSpecificPiece[(uint64_t)PieceType::ProSilver] = BitBoard(STRING_OF_START_PROSILVER);
        hasSpecificPiece[(uint64_t)PieceType::ProKnight] = BitBoard(STRING_OF_START_PROKNIGHT);
        hasSpecificPiece[(uint64_t)PieceType::ProLance] = BitBoard(STRING_OF_START_PROLANCE);
        hasSpecificPiece[(uint64_t)PieceType::ProPawn] = BitBoard(STRING_OF_START_PROPAWN);
    }
};
#endif
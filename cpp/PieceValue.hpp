#ifndef PIECE_VALUE_HPP
#define PIECE_VALUE_HPP

#include "PieceType.hpp"

class PieceValue{
private:
public:
    static int getValue(PieceType pieceType){
        switch (pieceType){
            using enum PieceType;
        case King     : return 15000;
        case Gold     : return   540;
        case Rook     : return   990;
        case Bichop   : return   855;
        case Silver   : return   495;
        case Knight   : return   405;
        case Lance    : return   315;
        case Pawn     : return    90;
        case Dragon   : return  1395;
        case Horse    : return   945;
        case ProSilver: return   540;
        case ProKnight: return   540;
        case ProLance : return   540;
        case ProPawn  : return   540;
        default       : return     0;
        }
    }
};

#endif
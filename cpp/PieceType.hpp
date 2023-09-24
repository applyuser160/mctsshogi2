#ifndef PIECE_TYPE_HPP
#define PIECE_TYPE_HPP

enum class PieceType
{
    Promote = 8, PieceTypeNumber = 15, NotProPieceTypeNumber = 8,
    None = 0, King, Gold, 
    Rook, Bichop, Silver, Knight, Lance, Pawn,
    Dragon, Horse, ProSilver, ProKnight, ProLance, ProPawn,
    PromoteChange = 6
};

#endif
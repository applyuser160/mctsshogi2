#ifndef PIECE_NAME_HPP
#define PIECE_NAME_HPP

enum class PieceName
{
    Empty = 0, UnPromoted = 0, Promoted = 8,
    BPawn = 1, BLance, BKnight, BSilver, BBishop, BRook, BGold, BKing,
    BProPawn, BProLance, BProKnight, BProSilver, BHorse, BDragon,
    WPawn = 17, WLance, WKnight, WSilver, WBishop, WRook, WGold, WKing,
    WProPawn, WProLance, WProKnight, WProSilver, WHorse, WDragon,
    PieceNone
};

#endif
#ifndef PIECE_HPP
#define PIECE_HPP

#include <bitset>
#include "PieceType.hpp"
#include "PieceName.hpp"
#include "HandPiece.hpp"
#include "MoveType.hpp"
#include "Direction.hpp"

class Piece
{
private:
    static char* convertString(PieceType pieceType){
        using enum PieceType;
        switch (pieceType){
        case None:
            return (char*)" ";
        case King:
            return (char*)"k";
        case Gold:  
            return (char*)"g";
        case Rook:
            return (char*)"r";
        case Bichop:
            return (char*)"b";
        case Silver:
            return (char*)"s";
        case Knight:
            return (char*)"n";
        case Lance:
            return (char*)"l";
        case Pawn:
            return (char*)"p";
        case Dragon:
            return (char*)"d";
        case Horse:
            return (char*)"h";
        case ProSilver:
            return (char*)"+s";
        case ProKnight:
            return (char*)"+n";
        case ProLance:
            return (char*)"+l";
        case ProPawn:
            return (char*)"+p";
        default:
            return (char*)"";
        }
    }
public:
    ColorType owner;
    PieceType type;
    Piece(){
        owner = ColorType::None;
        type = PieceType::None;
    }
    Piece(ColorType colorType, PieceType pieceType){
        owner = colorType;
        type = pieceType;
    }
    Piece(int num){
        std::bitset<5> bit(num);
        owner = (ColorType)(int)bit[0];
        bit >>= 1;
        type = (PieceType)bit.to_ulong();
    }
    int toInt(){
        int result = (int)type;
        result <<= 1;
        result += (int)owner;
        return result;
    }
    char* toString(){
        return convertString(type);
    }
    static void getMoveType(MoveType moveTypes[(int)DirectionName::DirectionNameNumber], PieceType pieceType){
        using enum PieceType;
        switch (pieceType){
        case None:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = None;
            moveTypes[(int)UP_LEFT] = None;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = None;
            break;
            }
        case King:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = Short;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = Short;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case Gold:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case Rook:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Long;
            moveTypes[(int)UP_LEFT] = None;
            moveTypes[(int)LEFT] = Long;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = Long;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = Long;
            moveTypes[(int)UP_RIGHT] = None;
            break;
            }
        case Bichop:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = None;
            moveTypes[(int)UP_LEFT] = Long;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = Long;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = Long;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = Long;
            break;
            }
        case Silver:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = Short;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = Short;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case Knight:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = None;
            moveTypes[(int)UP_LEFT] = Hop;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = Hop;
            break;
            }
        case Lance:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Long;
            moveTypes[(int)UP_LEFT] = None;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = None;
            break;
            }
        case Pawn:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = None;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = None;
            break;
            }
        case Dragon:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Long;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Long;
            moveTypes[(int)DOWN_LEFT] = Short;
            moveTypes[(int)DOWN] = Long;
            moveTypes[(int)DOWN_RIGHT] = Short;
            moveTypes[(int)RIGHT] = Long;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case Horse:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Long;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = Long;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = Long;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Long;
            break;
            }
        case ProSilver:
        case ProKnight:
        case ProLance:
        case ProPawn:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        }
    }
    static bool ablePro(PieceType pieceType){
        using enum PieceType;
        switch (pieceType){
        case None:
        case King:
        case Gold:  
            return false;
        case Rook:
        case Bichop:
        case Silver:
        case Knight:
        case Lance:
        case Pawn:
            return true;
        case Dragon:
        case Horse:
        case ProSilver:
        case ProKnight:
        case ProLance:
        case ProPawn:
            return false;
        default:
            return false;
        }
    }
    static char* toString(PieceType pieceType){
        return convertString(pieceType);
    }
};
#endif
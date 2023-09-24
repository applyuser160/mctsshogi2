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
    static char* convertString(PieceType pieceType, ColorType owner){
        char* result = new char[3];
        char* piece;
        bool isPromote;
        if ((int)pieceType > (int)PieceType::Promote){
            result[0] = '+';
            piece = &result[1];
            result[2] = '\0';
            pieceType = (PieceType)((int)pieceType - (int)PieceType::PromoteChange);
        }else{
            piece = &result[0];
            result[1] = '\0';
        }

        switch (pieceType){
            using enum PieceType;
        case None:
            *piece = ' ';
            break;
        case King:
            *piece = 'k';
            break;
        case Gold:  
            *piece = 'g';
            break;
        case Rook:
            *piece = 'r';
            break;
        case Bichop:
            *piece = 'b';
            break;
        case Silver:
            *piece = 's';
            break;
        case Knight:
            *piece = 'n';
            break;
        case Lance:
            *piece = 'l';
            break;
        case Pawn:
            *piece = 'p';
            break;
        default:
            *piece = ' ';
        }
        if (owner == ColorType::Black){
            *piece -= 32;
        }
        return result;
    }
    void convertFromString(char str){
        if (str > 83){
            owner = ColorType::White;
            str -= 32;
        }else{
            owner = ColorType::Black;
        }
        switch (str){
            using enum PieceType;
        case 'K': type = King; break;
        case 'G': type = Gold; break;
        case 'R': type = Rook; break;
        case 'B': type = Bichop; break;
        case 'S': type = Silver; break;
        case 'N': type = Knight; break;
        case 'L': type = Lance; break;
        case 'P': type = Pawn; break;
        default: type = None; break;
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
    Piece(char str){
        convertFromString(str);
    }
    Piece(char* str){
        int promote = 0;
        char pieceStr;
        if (str[0] == '+'){
            promote = (int)PieceType::PromoteChange;
            pieceStr = str[1];
        }else{
            pieceStr = str[0];
        }
        convertFromString(pieceStr);
        type = (PieceType)((int)type + promote);
    }

    int toInt(){
        int result = (int)type;
        result <<= 1;
        result += (int)owner;
        return result;
    }
    char* toString(){
        return convertString(type, owner);
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
    static char* toString(PieceType pieceType, ColorType owner){
        return convertString(pieceType, owner);
    }
};
#endif
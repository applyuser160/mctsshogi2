#ifndef HAND_HPP
#define HAND_HPP

#include "Piece.hpp"
#include "PieceType.hpp"
#include "ColorType.hpp"

/*
Hand
    pieces[16]
    counts[16]
     ->[ 0 to  7]:Black's pieces.
       [ 8 to 15]:White's pieces.
     ->The order is same to PieceType.
*/

class Hand{
private:
    int calcIndex(ColorType colorType, PieceType pieceType){
        using enum PieceType;
        return (int)colorType * (int)NotProPieceTypeNumber + (int)pieceType - 1;
    }
public:
    Piece pieces[(int)PieceType::NotProPieceTypeNumber * (int)ColorType::ColorNumber];
    int counts[(int)PieceType::NotProPieceTypeNumber * (int)ColorType::ColorNumber];
    Hand(){
        using enum ColorType;
        for (int j = (int)Black; j < (int)ColorNumber; j++){
            using enum PieceType;
            for (int i = (int)King; i <= (int)NotProPieceTypeNumber; i++){
                int index = j * (int)NotProPieceTypeNumber + i - 1;
                pieces[index] = Piece((ColorType)j, (PieceType)i);
                counts[index] = 0;
            }
        }
    }
    Piece getPiece(ColorType colorType, PieceType pieceType){
        int index = calcIndex(colorType, pieceType);
        return pieces[index];
    }
    int getCount(ColorType colorType, PieceType pieceType){
        int index = calcIndex(colorType, pieceType);
        return counts[index];
    }
    void addPiece(ColorType colorType, PieceType pieceType){
        int index = calcIndex(colorType, pieceType);
        counts[index]++;
    }
    void addPieces(ColorType colorType, PieceType pieceType, int count){
        int index = calcIndex(colorType, pieceType);
        counts[index] += count;
    }
    void decreasePiece(ColorType colorType, PieceType pieceType){
        int index = calcIndex(colorType, pieceType);
        counts[index]--;
    }
    int getPlayerPieces(Piece** pieces, ColorType colorType){
        using enum PieceType;
        int resultIndex = 0;
        (*pieces) = new Piece[(int)NotProPieceTypeNumber];
        for (int i = (int)King; i <= (int)NotProPieceTypeNumber; i++){
            int index = calcIndex(colorType, (PieceType)i);
            if (counts[index] > 0){
                (*pieces)[resultIndex] = (*this).pieces[index];
                resultIndex++;
            }
        }
        return resultIndex;
    }
};

#endif
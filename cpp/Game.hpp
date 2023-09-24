#ifndef GAME_HPP
#define GAME_HPP

#include <time.h>
#include <vector>

#include <random>
#include "Board.hpp"
#include "Random.hpp"

class Game{
private:
public:
    Board board;
    int moveNumber;
    ColorType turn;
    ColorType winner;
    Game(){
        board = Board();
        moveNumber = 1;
        turn = ColorType::Black;
        winner = ColorType::None;
    }
    Game(Board board, int moveNumber, ColorType turn, ColorType winner = ColorType::None){
        (*this).board = board;
        (*this).moveNumber = moveNumber;
        (*this).turn = turn;
        (*this).winner = winner;
    }

    void inputBoard(char* sfen){
        if (sfen == "startpos"){
            board.startpos();
        }
        char* currentSfen = &sfen[0];
        int consecutive = 0;
        for (int row = 1; row <= 9; row++){
            for (int column = 9; column >= 1; column--){
                if (*currentSfen > '0' && *currentSfen  <= '9'){
                    consecutive = *currentSfen  - 48;
                    currentSfen += 1;
                }
                if (consecutive > 0){
                    consecutive--;
                    continue;
                }
                if (*currentSfen == '/'){
                    currentSfen += 1;
                    column++;
                    continue;
                }
                int index = Address(column, row).toIndex();
                Piece piece = Piece(currentSfen);
                board.deploy(index, piece.type, piece.owner);
                if ((int)piece.type > (int)PieceType::Promote){
                    currentSfen += 2;
                }else{
                    currentSfen += 1;
                }
            }
        }
    }

    void inputHand(char* sfen){
        if (sfen == "-") return;
        char* currentSfen = &sfen[0];
        while(1){
            if (*currentSfen == '\0'){
                break;
            }
            if (*currentSfen > '0' && *currentSfen  <= '9'){
                int consecutive = *currentSfen  - 48;
                Piece piece = Piece(currentSfen[1]);
                board.hand.addPieces(piece.owner, piece.type, consecutive);
                currentSfen += 2;
            }else{
                Piece piece = Piece(currentSfen);
                board.hand.addPiece(piece.owner, piece.type);
                currentSfen += 1;
            }
        }
    }

    void inputMoveNumber(char* sfen){
        moveNumber = atoi(sfen);
    }

    void inputTurn(char* sfen){
        turn = Color::convertFromString(sfen[0]);
    }


    bool isFinished(ColorType* winner){
        using enum ColorType;
        board.isFinished(winner);
        if (*winner == Black || *winner == White){
            return true;
        }else if(moveNumber >= 500){
            return true;
        }else{
            return false;
        }
    }

    void executeMove(Move move){
        board.executeMove(move);
        moveNumber++;
        turn = Color::getReverseColor(turn);
    }

    Game randomPlay(){
        while(true){
            Move* moves;
            int moveCount = board.serchMoves(&moves, turn);
            Random random = Random(0, moveCount - 1);
            Move move = moves[random.generateOne()];
            delete[] moves;
            executeMove(move);
            bool isFinish = isFinished(&winner);
            if (isFinish){
                break;
            }
        }
        return (*this);
    }

    std::vector<int> timeMeasurements(){
        std::vector<int> times;

        while(true){
            struct timeval start, sec1;
            mingw_gettimeofday(&start, NULL);
            Move* moves;
            int moveCount = board.serchMoves(&moves, turn);
            mingw_gettimeofday(&sec1, NULL);
            Random random = Random(0, moveCount - 1);
            Move move = moves[random.generateOne()];
            executeMove(move);
            bool isFinish = isFinished(&winner);
            times.push_back(((sec1.tv_sec - start.tv_sec) * 1000000) + (sec1.tv_usec - start.tv_usec));
            if (isFinish){
                break;
            }
        }
        return times;
    }
};

#endif
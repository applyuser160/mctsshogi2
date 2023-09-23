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
    Game(Board board, int moveNumber, ColorType turn, ColorType winner){
        (*this).board = board;
        (*this).moveNumber = moveNumber;
        (*this).turn = turn;
        (*this).winner = winner;
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
#ifndef MCTS_RESULT_HPP
#define MCTS_RESULT_HPP

#include <vector>
#include <mutex>
#include <cstdint>
#include <iostream>
#include <thread>
#include "Board.hpp"
#include "ColorType.hpp"
#include "Move.hpp"

std::mutex mtx_;

class MctsResult{
private:
public:
    int** result;
    Move* nextMoves;
    int nextMoveCount;
    int count;

    MctsResult(){
        nextMoveCount = 0;
        count = 0;
    }

    MctsResult(int nextMoveCount, Move* nextMoves){
        count = 0;
        (*this).nextMoveCount = nextMoveCount;
        (*this).nextMoves = nextMoves;
        result = new int*[nextMoveCount];
        for (int i = 0; i < nextMoveCount; i++){
            result[i] = new int[(int)ColorType::ColorNumber + 1];
        }
        for (int i = 0; i < nextMoveCount; i++){
            for (int j = 0; j < (int)ColorType::ColorNumber + 1; j++){
                result[i][j] = 0;
            }
        }
    }

    void deleteResult(){
        delete[] nextMoves;
        for (int i = 0; i < nextMoveCount; i++){
            delete result[i];
        }
        delete[] result;
    }

    void plusResult(ColorType winner, int nextMoveIndex){
        std::lock_guard<std::mutex> lock(mtx_);
        if ((int)winner > -1){
            result[nextMoveIndex][(int)winner]++;
        }
        result[nextMoveIndex][(int)ColorType::ColorNumber]++;
        count++;
    }

    void calcResult(ColorType turn){
        int bestIndex = 0;
        float bestWinPer = 0.0;
        using enum ColorType;
        for (int i = 0; i < nextMoveCount; i++){
            float total = result[i][(int)ColorNumber];
            float currentTurnWin = (bool)turn ? result[i][(int)White] : result[i][(int)Black];
            float winPer = currentTurnWin / total;
            if (winPer > bestWinPer){
                bestWinPer = winPer;
                bestIndex = i;
            }
        }
        // std::cout << count << " times played!\n";
        std::cout << "bestmove " << nextMoves[bestIndex].toString() << "\n";

        deleteResult();
    }
};

#endif
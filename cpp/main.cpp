#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>
#include "BitBoard.hpp"
#include "Board.hpp"
#include "Address.hpp"
#include "Game.hpp"
#include "Piece.hpp"
#include "Hand.hpp"
#include <time.h>
#include <vector>

int main() {
/*ランダムに手を指す*/
    // std::vector<Game> games;

    // struct timeval start, end;
    // mingw_gettimeofday(&start, NULL);
    // int limit = 5;
    // while(1){
    //     mingw_gettimeofday(&end, NULL);
    //     if (((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec) > 1000000 * limit){
    //         break;
    //     }

    //     Game game = Game();
    //     games.push_back(game.randomPlay());
    // }
    // int size = games.size();
    // printf("count: %d\n", size);
    // int* winner = new int[3];
    // int sumMoveNumber = 0;
    // for (int i = 0; i< size; i++){
    //     winner[((int)games[i].winner) + 1] += 1;
    //     sumMoveNumber += games[i].moveNumber;
    // }
    // printf("draw: %d, black: %d, white: %d\n", winner[0], winner[1], winner[2]);
    // printf("average move number: %lf\n", (double)sumMoveNumber / (double)size);
    // delete[] winner;
/*ランダムに手を指す*/

/*csa文字列の解析*/
    Move move = Move((char*)"p*6b");
    printf("move: %s\n", move.toString());
/*csa文字列の解析*/

/*sfen文字列の解析*/
    Game game = Game();
    game.inputBoard((char*)"lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL");
    // game.inputBoard((char*)"startpos");
    game.inputHand((char*)"-");
    game.inputMoveNumber((char*)"1");
    game.inputTurn((char*)"b");
/*sfen文字列の解析*/

/*入力を受け取る*/
    std::string command;
    std::cin >> command;
    std::cout << command;
/*入力を受け取る*/

}
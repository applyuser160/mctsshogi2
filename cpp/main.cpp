#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <cstdint>
#include <bitset>
#include <thread>
#include "BitBoard.hpp"
#include "Board.hpp"
#include "Address.hpp"
#include "Game.hpp"
#include "Piece.hpp"
#include "Hand.hpp"
#include "Usi.hpp"
#include "MctsResult.hpp"
#include <time.h>
#include <vector>
#include <unistd.h>

int main() {
/*ランダムに手を指す*/
    // std::vector<Game> games;

    // struct timeval start, end;
    // mingw_gettimeofday(&start, NULL);
    // int limit = 60;
    // while(1){
    //     mingw_gettimeofday(&end, NULL);
    //     if (((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec) > 1000000 * limit){
    //         break;
    //     }
    //     Game game = Game();
    //     game.inputBoard((char*)"startpos");
    //     games.push_back(game.randomPlay());
    // }
    // int size = games.size();
    // printf("count: %d\n", size);
    // int* winner = new int[3];
    // for (int i = 0; i < 3; i++) winner[i] = 0;
    // int sumMoveNumber = 0;
    // for (int i = 0; i< size; i++){
    //     winner[((int)games[i].winner) + 1]++;
    //     sumMoveNumber += games[i].moveNumber;
    // }
    // printf("draw: %d, black: %d, white: %d\n", winner[0], winner[1], winner[2]);
    // printf("average move number: %lf\n", (double)sumMoveNumber / (double)size);
    // delete[] winner;
/*ランダムに手を指す*/

/*csa文字列の解析*/
    // Move move = Move((char*)"6f6i");
    // printf("move: %s\n", move.toString());
/*csa文字列の解析*/

/*sfen文字列の解析*/
    // Game game = Game();
    // game.inputBoard((char*)"lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL");
    // // game.inputBoard((char*)"startpos");
    // game.inputHand((char*)"-");
    // game.inputMoveNumber((char*)"1");
    // game.inputTurn((char*)"b");
/*sfen文字列の解析*/

/*入力を受け取る*/
    // std::string command;
    // std::cin >> command;
    // std::cout << command;
/*入力を受け取る*/

/*本番*/
    // Usi usi = Usi();
    // while(1){
    //     usi.inputCommand();
    // }
/*本番*/

/*非同期処理*/
    Usi usi = Usi();
    usi.game = Game();
    usi.game.inputBoard((char*)"startpos\0");
    // std::cout << "haspiece:" << game.board.hasPiece.board << "\n";
    // std::cout << "black   :" << game.board.playerPossession[0].board << "\n";
    // std::cout << "white   :" << game.board.playerPossession[1].board << "\n";
    // std::cout << "none    :" << game.board.hasSpecificPiece[0].board << "\n";
    // std::cout << "king    :" << game.board.hasSpecificPiece[1].board << "\n";
    // std::cout << "gold    :" << game.board.hasSpecificPiece[2].board << "\n";
    // std::cout << "rook    :" << game.board.hasSpecificPiece[3].board << "\n";
    // std::cout << "bichop  :" << game.board.hasSpecificPiece[4].board << "\n";
    // std::cout << "silver  :" << game.board.hasSpecificPiece[5].board << "\n";
    // std::cout << "knight  :" << game.board.hasSpecificPiece[6].board << "\n";
    // std::cout << "lance   :" << game.board.hasSpecificPiece[7].board << "\n";
    // std::cout << "pawn    :" << game.board.hasSpecificPiece[8].board << "\n";
    usi.commandGo(std::vector<std::string> {"go"});
    std::cout << "thinking...\n";
    sleep(10);
    std::cout << "sleeped\n";
    usi.commandStop();
/*非同期処理*/

    // int nextMoveCount = 30;
    // int** result = new int*[nextMoveCount];
    // for (int i = 0; i < nextMoveCount; i++){
    //     result[i] = new int[(int)ColorType::ColorNumber + 1];
    // }

    // result[0][0]++;

    // for (int i = 0; i < nextMoveCount; i++){
    //     for (int j = 0; j < 3; j++){
    //         printf("[%d,%d]:%p,%d\n", i, j, &result[i][j], result[i][j]);
    //     }
    // }

    return 0;
}
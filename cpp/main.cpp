#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>
#include "BitBoard.hpp"
#include "Board.hpp"
#include "Address.hpp"
#include "Game.hpp"
#include <time.h>
#include <vector>

int main() {
/*ランダムに手を指す*/
    std::vector<Game> games;

    struct timeval start, end;
    mingw_gettimeofday(&start, NULL);
    int limit = 5;
    while(1){
        mingw_gettimeofday(&end, NULL);
        if (((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec) > 1000000 * limit){
            break;
        }

        Game game = Game();
        games.push_back(game.randomPlay());
    }
    int size = games.size();
    printf("count: %d\n", size);
    int* winner = new int[3];
    int sumMoveNumber = 0;
    for (int i = 0; i< size; i++){
        winner[((int)games[i].winner) + 1] += 1;
        sumMoveNumber += games[i].moveNumber;
    }
    printf("draw: %d, black: %d, white: %d\n", winner[0], winner[1], winner[2]);
    printf("average move number: %lf\n", (double)sumMoveNumber / (double)size);
    delete[] winner;
/*ランダムに手を指す*/



}
#ifndef USI_HPP
#define USI_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include "UsiStatusType.hpp"
#include "UsiCommand.hpp"
#include "Game.hpp"
#include "MctsResult.hpp"

const int numThread = 10;

class Usi{
private:
public:
    UsiStatusType status;
    Game game;
    MctsResult result;
    std::vector<Game> games;
    std::vector<std::thread> threads;
    bool isStop;
    Usi(){
        status = UsiStatusType::WaitUsi;
        game = Game();
        result = MctsResult();
    }

    void command404(std::string command){
        std::cout << "[ERROR] command `" << command << "` is not found!\n";
    }

    void commandUsi(){
        std::cout << "id name mctsShogi\n";
        std::cout << "id author mctsShogi\n";
        std::cout << "usiok\n";
        status = UsiStatusType::WaitIsready;
    }

    void commandIsready(){
        game = Game();
        std::cout << "readyok\n";
        status = UsiStatusType::Ready;
    }

    void commandUsinewgame(){
        game = Game();
        std::cout << "newgame\n";
        status = UsiStatusType::Ready;
    }

    void commandPosition(std::vector<std::string> options){
        char *board, *turn, *hand, *moveNum;
        int moveIndex = 0;
        board = new char[options[1].size() + 1];
        std::char_traits<char>::copy(board, options[1].c_str(), options[1].size() + 1);
        if (options[1] == "startpos"){
            turn = (char*)"b";
            hand = (char*)"-";
            moveNum = (char*)"1";
            moveIndex = 2;
        }else{
            turn = new char[options[2].size() + 1];
            std::char_traits<char>::copy(turn, options[2].c_str(), options[2].size() + 1);
            hand = new char[options[3].size() + 1];
            std::char_traits<char>::copy(hand, options[3].c_str(), options[3].size() + 1);
            moveNum = new char[options[4].size() + 1];
            std::char_traits<char>::copy(moveNum, options[4].c_str(), options[4].size() + 1);
            moveIndex = 5;
        }
        
        game.inputBoard(board);
        game.inputTurn(turn);
        game.inputHand(hand);
        game.inputMoveNumber(moveNum);

        if (options[moveIndex] == "moves"){
            moveIndex++;
            for (int i = moveIndex; i < options.size(); i++){
                char *moveStr = new char[options[i].size() + 1];
                std::char_traits<char>::copy(moveStr, options[i].c_str(), options[i].size() + 1);
                game.executeMove(Move(moveStr));
            }
        }

        status = UsiStatusType::Ready;
        delete[] board;
        if (options[1] != "startpos"){
            delete[] turn;
            delete[] hand;
            delete[] moveNum;
        }
        std::cout << "set position\n";
    }

    void commandGo(std::vector<std::string> options){
        /*マルチスレッドで実装*/
        status = UsiStatusType::Thinking;
        isStop = false;
        Move* nextMoves;
        int nextMoveCount = game.board.serchMoves(&nextMoves, game.turn);
        result = MctsResult(nextMoveCount, nextMoves);
        for (int i = 0; i < numThread; i++){
            games.push_back(game);
        }
        for (int i = 0; i < numThread; i++){
            Game* c = &games[i];
            threads.push_back(std::thread([c, this]{(*c).randomMove(&(*this).result, &(*this).isStop);}));
        }
    }

    void commandStop(){
        isStop = true;
        for (int i = 0; i < numThread; i++){
            threads[i].join();
        }
        for (int i = 0; i < numThread; i++){
            threads.pop_back();
        }
        result.calcResult(game.turn);
        delete[] result.nextMoves;
        status = UsiStatusType::Ready;
    }

    void commandQuit(){
        std::exit(0);
    }

    void inputCommand(){
        std::string line;
        std::getline(std::cin, line);

        std::vector<std::string> command;

        std::basic_stringstream ss(line);
        std::string buf;
        while (ss >> buf){
            command.push_back(buf);
        }

        switch (status){
            using enum UsiStatusType;
            using enum UsiCommandType;
        case WaitUsi:
            if (command[0] == UsiCommand::getUsiCommandString(Usi)){
                commandUsi();
            }else if (command[0] == UsiCommand::getUsiCommandString(Quit)){
                commandQuit();
            }else{
                command404(command[0]);
            }
            return;
        case WaitIsready:
            if (command[0] == UsiCommand::getUsiCommandString(Isready)){
                commandIsready();
            }else if (command[0] == UsiCommand::getUsiCommandString(Quit)){
                commandQuit();
            }else{
                command404(command[0]);
            }
            return;
        case Ready:
            if (command[0] == UsiCommand::getUsiCommandString(UsiNewGame)){
                commandUsinewgame();
            }else if (command[0] == UsiCommand::getUsiCommandString(Position)){
                commandPosition(command);
            }else if (command[0] == UsiCommand::getUsiCommandString(Go)){
                commandGo(command);
            }else if (command[0] == UsiCommand::getUsiCommandString(Quit)){
                commandQuit();
            }else{
                command404(command[0]);
            }
            return;
        case Thinking:
            if (command[0] == UsiCommand::getUsiCommandString(Stop)){
                commandStop();
            }else if (command[0] == UsiCommand::getUsiCommandString(Quit)){
                commandQuit();
            }else{
                command404(command[0]);
            }
            return;
        default:
            command404(command[0]);
            return;
        }
    }
};

#endif
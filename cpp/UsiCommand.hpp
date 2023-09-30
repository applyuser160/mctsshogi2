#ifndef USI_COMMAND_HPP
#define USI_COMMAND_HPP

#include <string>

enum class UsiCommandType{
    Usi, Isready, SetOption, UsiNewGame, Position, Go, Stop, Quit
};

static const std::string UsiCommandString[] = {
    "usi", "isready", "setoption", "usinewgame", "position", "go", "stop", "quit"
};

class UsiCommand{
private:
public:
    static const std::string getUsiCommandString(UsiCommandType usiCommandType){
        return UsiCommandString[(int)usiCommandType];
    }
};

#endif
#ifndef USI_COMMAND_HPP
#define USI_COMMAND_HPP

enum class UsiCommandType{
    Usi, Isready, SetOption, UsiNewGame, Position, Go, Stop, Quit
};

static const char* UsiCommandString[] = {
    "usi", "isready", "setoption", "usinewgame", "position", "go", "stop", "quit"
};

class UsiCommand{
private:
public:
    
};

#endif
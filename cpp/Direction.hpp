#ifndef DIRECTION_HPP
#define DIRECTION_HPP

enum class DirectionName{
    UP, UP_LEFT, LEFT, DOWN_LEFT, DOWN, DOWN_RIGHT, RIGHT, UP_RIGHT,
    DirectionNameNumber = 8
};

class Direction
{
private:
public:
    DirectionName name;
    int verticalVector;
    int horizonVector;
    Direction(DirectionName name){
        (*this).name = name;
        switch (name){
            using enum DirectionName;
        case UP:
            verticalVector = -1;
            horizonVector = 0;
            break;
        case UP_LEFT:
            verticalVector = -1;
            horizonVector = 1;
            break;
        case LEFT:
            verticalVector = 0;
            horizonVector = 1;
            break;
        case DOWN_LEFT:
            verticalVector = 1;
            horizonVector = 1;
            break;
        case DOWN:
            verticalVector = 1;
            horizonVector = 0;
            break;
        case DOWN_RIGHT:
            verticalVector = 1;
            horizonVector = -1;
            break;
        case RIGHT:
            verticalVector = 0;
            horizonVector = -1;
            break;
        case UP_RIGHT:
            verticalVector = -1;
            horizonVector = -1;
            break;
        }
    }
    Direction reverse(){
        verticalVector *= -1;
        horizonVector *= -1;
        return (*this);
    }
};
#endif
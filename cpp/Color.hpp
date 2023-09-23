#ifndef COLOR_HPP
#define COLOR_HPP

#include "ColorType.hpp"

class Color{
private:
public:
    static ColorType getReverseColor(ColorType colorType){
        switch (colorType){
            using enum ColorType;
        case Black:
            return White;
        case White:
            return Black;
        default:
            return None;
        }
    }
    static char* convertString(ColorType colorType){
        switch (colorType){
            using enum ColorType;
        case Black:
            return (char*)"B";
        case White:
            return (char*)"W";
        default:
            return (char*)"D";
        }
    }
};

#endif
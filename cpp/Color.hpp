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
            return (char*)"b";
        case White:
            return (char*)"w";
        default:
            return (char*)"d";
        }
    }
    static ColorType convertFromString(char str){
        switch (str){
            using enum ColorType;
        case 'b':
            return Black;
        case 'w':
            return White;
        default:
            return None;
        }
    }
};

#endif
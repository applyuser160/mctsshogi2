#ifndef COMMON_HPP
#define COMMON_HPP

#define BIT_NUMBER_ULL 64

class Common{
private:
public:
    static char alphabetToNumber(char alphabet){
        return alphabet - 48;
    }
    static char numberToAlphabet(char number){
        return number + 48;
    }
};

#endif
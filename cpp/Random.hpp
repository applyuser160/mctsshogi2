#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <fstream>

class Random{
private:
public:
    std::random_device seed_gen;
    std::default_random_engine engine;
    std::uniform_int_distribution<> dist;
    Random(){
        std::random_device seed_gen;
        engine = std::default_random_engine(seed_gen());
        dist = std::uniform_int_distribution<>(0, 9);
    }
    Random(int min, int max){
        std::random_device seed_gen;
        engine = std::default_random_engine(seed_gen());
        dist = std::uniform_int_distribution<>(min, max);
    }

    int generateOne(){
        return dist(engine);
    }

    int* generateMulti(int length){
        int* result = new int[length];
        for (int i = 0; i < length; i++){
            result[i] = dist(engine);
        }
        return result;
    }
    
};

#endif
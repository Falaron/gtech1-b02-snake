#include "../include/fruit.hpp"
#include <iostream>
#include <chrono>
#include <random>

Fruit::Fruit(){
    PosX = 0;
    PosY = 0;
    Randomizer();
};

int ran(){
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(0, 24);

    return distrib(gen);
}

int Fruit::Randomizer(){
    PosX = ran();
    PosY = ran();

    return 1;
}
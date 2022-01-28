#include "../include/snake.hpp"

int Snake::New(){
    PositionX = 5;
    PositionY = 5;

    return 1;
};

void Snake::Move(int DirectionX, int DirectionY){
    PositionX += DirectionX;
    PositionY += DirectionY;
};

int Snake::CheckCollide(){
    return 1;
};

void Snake::Eat(){
    return;
};
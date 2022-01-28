#include "../include/snake.hpp"
#include <stdio.h>


int Snake::New(){
    PositionX = 5;
    PositionY = 5;

    return 1;
};

void Snake::Move(int DirectionX, int DirectionY){
    PositionX += DirectionX;
    PositionY += DirectionY;
};

int Snake::CheckCollide(int winWidth, int winHeight){
    //posX posY if( < winWidth)
    return 1;
};

void Snake::Eat(){
    return;
};
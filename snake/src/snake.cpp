#include "../include/snake.hpp"
#include <stdio.h>

int Snake::New(){
    PosX = 0;
    PosY = 0;
    Size = 1;

    printf("New Snake : %d/%d\n", PosX, PosY);
    
    return 1;
};

void Snake::Move(int DirectionX, int DirectionY){
    printf("Move Snake : %d/%d\n", DirectionX, DirectionY);
    PosX += DirectionX;
    PosY += DirectionY;
};

int Snake::CheckCollide(){
    return 1;
};

void Snake::Eat(){

    Size += 1

    return;
};
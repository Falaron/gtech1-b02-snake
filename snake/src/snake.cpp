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
    //printf("Move Snake : %d/%d\n", DirectionX, DirectionY);
    PosX += DirectionX;
    PosY += DirectionY;
};

int Snake::CheckCollide(int winWidth, int winHeight, int Size){
    winWidth = winWidth/Size+4;
    winHeight = winHeight/Size+4;
    if(PosX > winWidth || PosX < 0 || PosY > winHeight || PosY < 0){
        PosX = 15;
        PosY = 15;
    }
    return 1;
};

void Snake::Eat(){

    Size += 1;

    return;
};
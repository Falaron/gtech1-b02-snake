#include "../include/snake.hpp"
#include <stdio.h>

Snake::Snake(){
    Size = 1;

    Segment *tail = new Segment(0,0);
    Head = tail;
    Last = tail;

    PosX = Head->GridX;
    PosY = Head->GridY;

    printf("New Snake : %d/%d\n", PosX, PosY);
}

void Snake::Move(int DirectionX, int DirectionY){
    Head->GridX += DirectionX;
    Head->GridY += DirectionY;
    PosX = Head->GridX;
    PosY = Head->GridY;
};

int Snake::Draw(int WindowSize, SDL_Renderer ** renderer){
    Head->Update(WindowSize, renderer);
    return 1;
}

int Snake::CheckCollide(int winWidth, int winHeight, int Size){
    winWidth = winWidth/Size+4;
    winHeight = winHeight/Size+4;
    if(PosX > winWidth || PosX < 0 || PosY > winHeight || PosY < 0){
        printf("STOP");
    }
    return 1;
};

void Snake::Eat(){
    Segment *body = new Segment(PosX, PosY);
    Last->next = body;
    Last = body;
    return;
};
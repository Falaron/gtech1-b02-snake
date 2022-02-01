#include "../include/snake.hpp"
#include <stdio.h>

Snake::Snake(){
    Size = 1;

    Segment *tail = new Segment(0,0);
    Head = tail;
    Last = tail;

    printf("New Snake : %d/%d\n", PosX, PosY);
}

void Snake::Move(int DirectionX, int DirectionY){
    Head->GridX += DirectionX;
    Head->GridY += DirectionY;
};

int Snake::Draw(int WindowSize, SDL_Renderer ** renderer){
    Head->Update(WindowSize, renderer);
    return 1;
}

int Snake::CheckCollide(int winWidth, int winHeight){
    //posX posY if( < winWidth)
    return 1;
};

void Snake::Eat(){
    Segment *body = new Segment(Head->GridX,Head->GridY);
    Last->next = body;
    Last = body;
    return;
};
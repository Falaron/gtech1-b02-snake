#include "../include/segment.hpp"

Segment::Segment(int X, int Y){
    GridX = X;
    GridY = Y;

    OldX = X;
    OldY = Y;

    next = NULL;

    return;
}

void Segment::Update(int Pos, int WindowSize, SDL_Renderer ** renderer){
    int R = 38*Pos/102;
    int G = 199*Pos/38;
    int B = 250;
    int X = 98;

    if (Pos > 48){
        R = 17;
        G = 251;
        B = 250;
        X = 98;
    }
    SDL_SetRenderDrawColor(*renderer,R,G,B,X);
    SDL_Rect rect = {this->GridX*500/WindowSize, this->GridY*500/WindowSize, 500/WindowSize, 500/WindowSize};
    SDL_RenderFillRect(*renderer, &rect);

    if (next){
        next->GridX = this->OldX;
        next->GridY = this->OldY;
        next->Update(Pos+=1, WindowSize, renderer);
    }
    this->OldX = GridX;
    this->OldY = GridY;
}
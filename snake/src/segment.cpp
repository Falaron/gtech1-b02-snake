#include "../include/segment.hpp"

Segment::Segment(int X, int Y){
    GridX = X;
    GridY = Y;

    OldX = X;
    OldY = Y;

    return;
}

void Segment::Update(int WindowSize, SDL_Renderer ** renderer){
    //printf("here : %d/%d\n", this->GridX, this->GridY);
    
    SDL_SetRenderDrawColor(*renderer,255,255,255,255);
    SDL_Rect rect = {this->GridX*500/WindowSize, this->GridY*500/WindowSize, 500/WindowSize, 500/WindowSize};
    SDL_RenderFillRect(*renderer, &rect);

    if (next){
        next->GridX = this->OldX;
        next->GridY = this->OldY;
        next->Update(WindowSize, renderer);
    }
    this->OldX = GridX;
    this->OldY = GridY;
}
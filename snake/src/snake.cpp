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
    Head->Update(1, WindowSize, renderer);
    return 1;
}

int Snake::CheckCollide(int winWidth, int winHeight, int Size){
    winWidth = winWidth/Size+4;
    winHeight = winHeight/Size+4;
    if(PosX > winWidth || PosX < 0 || PosY > winHeight || PosY < 0){
        return 1;
    }
    return 0;
};

int Snake::CheckSnakeCollide(){
    int result[Size][2];
    if (!Head->next) return 0;

    Segment* Current = Head->next;

    for (int i = 0; i < Size; i++){
        
        if (PosX == Current->GridX && PosY == Current->GridY){
            return 1;
        }

        if (Current->next){
            Current = Current->next;
        }
    }
    return 0;
}

void Snake::Eat(){
    Size += 1;
    Segment *body = new Segment(PosX, PosY);
    Last->next = body;
    Last = body;
    return;
};

void Snake::DeleteSegments(){
    if (Head->next){
        Segment* Current = Head->next;

        for (int i = 0; i < Size-1; i++){
            Segment* thisSegment = Current;
            if (Current->next){
                Current = Current->next;
            }
            printf("Invoke delete\n");
            delete thisSegment;
        }
    }

    Head->next = NULL;
    Last = Head;
    Size = 1;
    PosX = 0;
    PosY = 0;
    Head->GridX = 0;
    Head->GridY = 0;
    Head->OldX = 0;
    Head->OldY = 0;
}

int Snake::GetSnakeSize(){
    return this->Size;
}
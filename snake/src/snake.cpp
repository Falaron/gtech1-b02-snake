#include "../include/snake.hpp"
#include <stdio.h>

Snake::Snake(){
    Size = 1;

    Segment *tail = new Segment(12,12);
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
    winHeight = (winHeight-100)/Size+4;
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
    PosX = 12;
    PosY = 12;
    Head->GridX = 12;
    Head->GridY = 12;
    Head->OldX = 12;
    Head->OldY = 12;
}

int ** Snake::GetSnakePosition(){
    int** result = new int*[Size];
    for(int i = 0; i < Size; ++i)
        result[i] = new int[1];

    result[0][0] = Head->GridX;
    result[0][1] = Head->GridX;
    if (!Head->next){
        return result;
    };

    Segment* Current = Head->next;

    for (int i = 0; i < Size-1; i++){
        result[i+1][0] = Current->GridX;
        result[i+1][1] = Current->GridX;
        printf("HERE\n");
        if (Current->next){
            Current = Current->next;
        }
    }
    return result;
}

int Snake::GetSnakeSize(){
    return this->Size;
}
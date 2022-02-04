#include <SDL2/SDL.h>
#include <iostream>
#include "segment.hpp"

class Snake {
    public:
        Snake();
        void Move(int X, int Y);
        int CheckCollide(int winWidth, int winHeight, int Size);
        void Eat();
        int Draw(int WindowSize, SDL_Renderer ** Renderer);
        void CheckSnakeCollide();
        int GetSnakeSize();

        int PosY;
        int PosX;
        int tail;

    private:
        int Direction;
        int Size;
        Segment* Head;
        Segment* Last;
};
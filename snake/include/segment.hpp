#include <SDL2/SDL.h>

class Segment{
    public:
        Segment *next;
        Segment *last;

        Segment(int X, int Y);
        void Update(int Pos, int WindowSize, SDL_Renderer ** renderer);

        int GridX;
        int GridY;

        int OldX;
        int OldY;
};
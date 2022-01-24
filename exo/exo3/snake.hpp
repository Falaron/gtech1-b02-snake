#include <SDL2/SDL.h>

class Snake {
    public:
        int Init(const char *WindowName, int Width, int Height);
        int GetRenderer();

        ~Snake();

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        int score;
        int X;
        int Y;
};
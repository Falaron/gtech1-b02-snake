#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Window {
    public:
        int New(const char *WindowName, int Width, int Height);
        int Draw(int X, int Y, int fruitX, int fruitY);
        int Refresh();
        int Destroy();
        void CheckKeys();
        int GetSize();

        int winWidth, winHeight;

        int DirectionX;
        int DirectionY;

        SDL_Event event;
        int closeRequest;
        Uint32 frame_time_start, frame_time;
        Uint32 frame_rate;

        int frameSlower;

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        int Size;
};
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_image.h>
#include <string>

class Window {
    public:
        int New(const char *WindowName, int Width, int Height);
        int Draw(int fruitX, int fruitY);
        int Refresh();
        int Destroy();
        int GetSize();
        SDL_Renderer ** GetRenderer();
        void CheckKeys(int SnakeSize);

        int winWidth, winHeight;

        int DirectionX;
        int DirectionY;

        SDL_Event event;
        int closeRequest;
        Uint32 frame_time_start, frame_time;
        Uint32 frame_rate;

        int frameSlower;
        /*TTF_Font * font;
        SDL_Surface* surfaceMessage;
        SDL_Texture* Message;*/

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        int Size;
        int doOnce;
};
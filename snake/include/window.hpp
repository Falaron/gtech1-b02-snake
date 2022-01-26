#include <SDL2/SDL.h>

class Window {
    public:
        int New(const char *WindowName, int Width, int Height);
        int Draw();
        int Refresh();
        int Destroy();
        void CheckKeys();

        SDL_Event event;
        int closeRequest;
        Uint32 frame_time_start, frame_time;
        Uint32 frame_rate;

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
};
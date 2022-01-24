#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string>

class MainSDLWindow {
    public:
        int Init(const char *WindowName, int Width, int Height);
        int GetRenderer();

        ~MainSDLWindow();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
};
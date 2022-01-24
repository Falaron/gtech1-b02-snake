#include "snake.hpp"

int Snake::Init(const char *WindowName, int Width, int Height){
    SDL_Event event;
    Uint32 frame_rate, frame_time = 50;

    X = 100;
    Y = 100;
    directionY = 0;
    directionX = 10;
    

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error while initializing SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création fenêtre.
    window = SDL_CreateWindow(WindowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        printf("Couldn't create window : %s", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL)
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_RenderClear(renderer);
    Draw();

    while(closeRequest == 0){

        Uint32 frame_time_start = SDL_GetTicks();

        SDL_WaitEvent(&event);

        CheckKeys();
        Draw();

        frame_time = SDL_GetTicks() - frame_time_start;

        if ( frame_time < frame_rate )
		{
			SDL_Delay( frame_rate - frame_time + 1 );
		}
        SDL_Delay(1000);
    }
     
    return EXIT_FAILURE;
}

void Snake::Draw(){
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_Rect rect = {X, Y, 50, 50};
    SDL_RenderFillRect(renderer, &rect); 
    SDL_RenderPresent(renderer);
}

void Snake::CheckKeys(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_UP]) {
        Y -= 10;
        directionX = 0;
        directionY = -10;
        return;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        Y += 10;
        directionX = 0;
        directionY = 10;
        return;
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        X -= 10;
        directionX = -10;
        directionY = 0;
        return;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        X += 10;
        directionX = 10;
        directionY = 0;
        return;
    }
    if (keystates[SDL_SCANCODE_ESCAPE]) {
        closeRequest = !closeRequest;
        return;
    }

    X += directionX;
    Y += directionY;
}

int Snake::GetRenderer(){
    return 1;
}

Snake::~Snake() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer); 
    SDL_Quit();
}

int main(void) {
    Snake main_window;
    main_window.Init("Test", 500, 500);
}
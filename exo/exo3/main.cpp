#include "snake.hpp"

int Snake::Init(const char *WindowName, int Width, int Height){
    SDL_Event event;

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

    SDL_SetRenderDrawColor(renderer,255,0,0,255);//Couleur rouge
    SDL_Rect rect = {100, 100, 100, 100};
    SDL_RenderFillRect(renderer, &rect); 
    SDL_RenderPresent(renderer);

    do {
        SDL_WaitEvent(&event);
    }while(event.type != SDL_QUIT);
     
    return EXIT_FAILURE;
}

int Snake::GetRenderer(){
    return 0;
    //return this->renderer;
}

Snake::~Snake() {
    SDL_DestroyWindow(window);
    //SDL_DestroyRenderer(renderer); 
    SDL_Quit();
}

int main(void) {
    Snake main_window;
    main_window.Init("Test", 500, 500);
}
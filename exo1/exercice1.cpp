#include "exercice1.hpp"

int MainSDLWindow::Init(const char *WindowName, int Width, int Height){
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

    do {
        SDL_WaitEvent(&event);
    }while(event.type != SDL_QUIT);
     
    return EXIT_FAILURE;
}

int MainSDLWindow::GetRenderer(){
    return this->renderer;
}

MainSDLWindow::~MainSDLWindow() {
    SDL_DestroyWindow(window);
    //SDL_DestroyRenderer(renderer); 
    SDL_Quit();
}

int main(void) {
    MainSDLWindow main_window;
    main_window.Init("Test", 500, 500);
}
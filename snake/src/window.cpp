#include "../include/window.hpp"

int Window::New(const char *WindowName, int Width, int Height){
    frame_rate = 10;
    frameSlower = 0;
    closeRequest = 0;
    DirectionX = 0;
    DirectionY = 0;
    Size = 25;

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

    //check windows size
    SDL_GetWindowSize(window, &winWidth, &winHeight);
    

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL)
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_RenderClear(renderer);

    return 1;
}

int Window::Destroy(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer); 
    SDL_Quit();

    return EXIT_FAILURE;
}

int Window::Draw(int SnakeX, int SnakeY, int FruitX, int FruitY){
    //Init Room
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);

    //Draw Room
    for(int row=0; row<Size; row++){
        for(int column=0; column<Size; column++){
            if(row == column || row%2 == 0 && column%2 == 0 || column%2 == 1 && row%2 == 1){
                SDL_SetRenderDrawColor(renderer,83,255,184,100);
            }else{
                SDL_SetRenderDrawColor(renderer,65,232,121,91);
            }
            SDL_Rect rect = {row*500/Size, column*500/Size, 500/Size, 500/Size};
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    //Draw Snake
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_Rect rect = {SnakeX*500/Size, SnakeY*500/Size, 500/Size, 500/Size};
    SDL_RenderFillRect(renderer, &rect);

    //Draw Fruit
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_Rect fruit = {FruitX*500/Size, FruitY*500/Size, 500/Size, 500/Size};
    SDL_RenderFillRect(renderer, &fruit);

    //Draw Score
    TTF_Font* Sans = TTF_OpenFont("ariali.ttf", 24);
    SDL_Color White = {255, 255, 255};

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    SDL_Surface* surfaceMessage =
        TTF_RenderText_Solid(Sans, "put your text here", White); 

    // now you can convert it into a texture
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate 
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    // Don't forget to free your surface and texture
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);

    return 1;
}

int Window::Refresh(){
    SDL_RenderPresent(renderer);
    return 1;
}

void Window::CheckKeys(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    

    if (keystates[SDL_SCANCODE_UP]) {
        printf("Up\n");
        DirectionX = 0;
        DirectionY = -1;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        printf("Down\n");
        DirectionX = 0;
        DirectionY = 1;
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        printf("Left\n");
        DirectionX = -1;
        DirectionY = 0;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        printf("Right\n");
        DirectionX = 1;
        DirectionY = 0;
    }

    if (keystates[SDL_SCANCODE_ESCAPE]) {
        closeRequest = 1;
        return;
    }
}

int Window::GetSize(){
    return Size;
}
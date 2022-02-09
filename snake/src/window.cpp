#include "../include/window.hpp"


Window::Window(const char *WindowName, int Width, int Height){
    frame_rate = 10;
    frameSlower = 0;
    closeRequest = 0;
    DirectionX = 0;
    DirectionY = 0;
    Size = 25;
    scoreX = 400;
    scoreY = 90;
    

    winWidth = Width;
    winHeight = Height-100;

    

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error while initializing SDL : %s", SDL_GetError());
        return;
    }
    TTF_Init();
    font = TTF_OpenFont("arial.ttf", 25);
    color = { 255, 255, 255 };

    	

    // Création fenêtre.
    window = SDL_CreateWindow(WindowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        printf("Couldn't create window : %s", SDL_GetError());
        return;
    }

    //check windows size
    SDL_GetWindowSize(window, &winWidth, &winHeight);
    

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL)
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return;
    }

    SDL_RenderClear(renderer);

    return;
}

int Window::Destroy(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);	
    //TTF_Quit();
    SDL_Quit();

    return EXIT_FAILURE;
}

int Window::Draw(int FruitX, int FruitY){
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

    //Draw Fruit
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_Rect fruit = {FruitX*500/Size, FruitY*500/Size, 500/Size, 500/Size};
    SDL_RenderFillRect(renderer, &fruit);

    return 1;
}

int Window::DrawScore(int scoreX, int scoreY, int snakeSize) {
    std::string scoreText = "Score : "+ std::to_string(snakeSize);
    surface = TTF_RenderText_Solid(font, scoreText.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, 0, 0);
    SDL_Rect scoreRect = { 50, 505, scoreX, scoreY };
    SDL_RenderCopy(renderer, texture, NULL, &scoreRect);

    return  1;
}

int Window::Refresh(){
    SDL_RenderPresent(renderer);
    return 1;
}

void Window::CheckKeys(int SnakeSize){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    

    if (keystates[SDL_SCANCODE_UP]) {
        if(SnakeSize > 1 && DirectionY == 1 && DirectionX == 0) return;
        DirectionX = 0;
        DirectionY = -1;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        if(SnakeSize > 1 && DirectionY == -1 && DirectionX == 0) return;
        DirectionX = 0;
        DirectionY = 1;
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        if(SnakeSize > 1 && DirectionY == 0 && DirectionX == 1) return;
        DirectionX = -1;
        DirectionY = 0;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        if(SnakeSize > 1 && DirectionY == 0 && DirectionX == -1) return;
        DirectionX = 1;
        DirectionY = 0;
    }

    if (keystates[SDL_SCANCODE_ESCAPE]) {
        closeRequest = 1;
        return;
    }

}

int Window::GetSize(){
    return this->Size;
}

SDL_Renderer ** Window::GetRenderer(){
    return &renderer;
}
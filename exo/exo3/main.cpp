#include "snake.hpp"

int Snake::Init(const char *WindowName, int Width, int Height){
    SDL_Event event;
    Uint32 frame_rate = 20;
    Uint32 frame_time_start, frame_time;
    int doOnce = 0;

    X = 100;
    Y = 100;
    totalCol = 10;
    totalRow = 10;
    directionY = 0;
    directionX = 3;
    closeRequest = 0;
    
    speed = 3;

    int screenWidth = Width;
    int screenHeight = Height;
    printf("%d",screenWidth);

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
    SDL_WaitEvent(&event);

    while(closeRequest == 0){

        frame_time_start = SDL_GetTicks();

        SDL_PollEvent(&event);

        CheckKeys();
        Draw();

        frame_time = SDL_GetTicks() - frame_time_start;

        if ( frame_time < frame_rate )
		{
			//SDL_Delay( frame_rate - frame_time + 1 );
            /*printf("frame time : %d\n", frame_time);
            printf("frame rate : %d\n", frame_rate);
            printf("%d\n", frame_rate - frame_time);*/
            SDL_Delay(frame_rate - frame_time);
		}
    }
     
    return EXIT_FAILURE;
}

void Snake::Draw(){
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
    rectX = 0;
    rectY = 0;
    for (int row = 0; row < totalRow; row++) {
        for (int col = 0; col < totalCol; col++){
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_Rect gridRect = {rectX, rectY, 500, 500};
            SDL_RenderDrawRect(renderer, &gridRect);
            rectX += 500/totalCol;
        }
        rectY += 500/totalRow;
    }
    

    //Print Snake
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_Rect rect = {X, Y, 50, 50};
    SDL_RenderFillRect(renderer, &rect); 
    SDL_RenderPresent(renderer);
}

void Snake::CheckKeys(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if(event.type == SDLK_KEYUP){
        printf("f");
        if (keystates[SDL_SCANCODE_UP]) {
        directionY += -1;
        return;
        }
        if (keystates[SDL_SCANCODE_DOWN]) {
            directionY += 1;
            return;
        }
        if (keystates[SDL_SCANCODE_LEFT]) {
            directionX += -1;
            return;
        }
        if (keystates[SDL_SCANCODE_RIGHT]) {
            directionX += 1;
            return;
        }
    }

    
    if (keystates[SDL_SCANCODE_ESCAPE]) {
        closeRequest = !closeRequest;
        return;
    }

    ConvertPosition(directionX, directionY);
    //printf("%d %d \n",directionY,coordY);

    X = coordX;
    Y = coordY;
}

int Snake::GetRenderer(){
    return 1;
}

Snake::~Snake() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer); 
    SDL_Quit();
}

int Snake::ConvertPosition(int rectX, int rectY){
    coordX = rectX*500/40;
    coordY = rectY*500/40;
    return coordX, coordY;
}

int main(void) {
    Snake main_window;
    main_window.Init("Test", 500, 500);
}
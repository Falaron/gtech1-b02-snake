#include "include/window.hpp"
#include "include/snake.hpp"
#include "include/fruit.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

int main(void){
    Snake snake_obj;
    Fruit fruit_obj;
    Window * main_window = new Window("Snake", 500, 600);

    while(main_window->closeRequest == 0){
        int Size = main_window->GetSize();
        main_window->frame_time_start = SDL_GetTicks();

        SDL_PollEvent(&main_window->event);

        main_window->frame_time = SDL_GetTicks() - main_window->frame_time_start;

        while (SDL_PollEvent(&main_window->event) != 0)
        {
            if (main_window->event.type == SDL_QUIT){
                main_window->closeRequest = 1;
                break;
            }
        }

        if ( main_window->frame_time < main_window->frame_rate )
		{
            
            main_window->CheckKeys(snake_obj.GetSnakeSize());
            if(main_window->frameSlower >= 12){

                if(fruit_obj.PosX == snake_obj.PosX && fruit_obj.PosY == snake_obj.PosY){
                    fruit_obj.Randomizer();
                    //change fruit position if spawn on snake
                    for (int i=0; i < snake_obj.GetSnakeSize(); i++){
                        if(fruit_obj.PosX == snake_obj.GetSnakePosition()[i][0] && fruit_obj.PosY == snake_obj.GetSnakePosition()[i][1]){
                            //printf("spawn inside snake body\n");
                            fruit_obj.Randomizer();
                        }
                    }
                    snake_obj.Eat();
                }
                int Collide = snake_obj.CheckCollide(main_window->winWidth, main_window->winHeight, Size);
                snake_obj.Move(main_window->DirectionX, main_window->DirectionY);
                main_window->Draw(fruit_obj.PosX, fruit_obj.PosY);
                snake_obj.Draw(main_window->GetSize(), main_window->GetRenderer());
                main_window->DrawScore(main_window->scoreX,main_window->scoreY,snake_obj.GetSnakeSize());
                main_window->Refresh();
                if (Collide == 0){
                    Collide = snake_obj.CheckSnakeCollide();
                }
                
                if(Collide==1){
                    snake_obj.DeleteSegments();
                    main_window->DirectionX = 0;
                    main_window->DirectionY = 0;

                    main_window->Draw(fruit_obj.PosX, fruit_obj.PosY);
                    snake_obj.Draw(main_window->GetSize(), main_window->GetRenderer());
                    main_window->DrawScore(main_window->scoreX,main_window->scoreY,snake_obj.GetSnakeSize());
                    main_window->Refresh();
                    SDL_Delay(1000);
                }

                main_window->frameSlower = 0;
            }
            main_window->frameSlower ++;
            SDL_Delay(main_window->frame_rate - main_window->frame_time);
		}
    }
    return main_window->Destroy();
}
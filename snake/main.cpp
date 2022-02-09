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
                snake_obj.Eat();
                if(fruit_obj.PosX == snake_obj.PosX && fruit_obj.PosY == snake_obj.PosY){
                    fruit_obj.Randomizer();

                    int ** slotAvaiable = new int*[main_window->winWidth];
                    for(int i = 0; i < main_window->winWidth; ++i)
                        slotAvaiable[i] = new int[main_window->winWidth];
                        for(int y = 0; y < main_window->winWidth; ++y){
                            printf("going append");
                            slotAvaiable[i].append(y);
                            printf("after");
                        }
                        printf("Slot avaiable : %d \n",slotAvaiable);

                    //for (int i=0; i < snake_obj.GetSnakeSize(); i++){
                        




                        /*if(fruit_obj.PosX == Pos[i][0] && fruit_obj.PosY == Pos[i][1]){
                            printf("Ca a spawn\n");
                            fruit_obj.Randomizer();
                        }*/
                    //}
                    snake_obj.Eat();
                }
                int Collide = snake_obj.CheckCollide(main_window->winWidth, main_window->winHeight, Size);
                //printf("CREATE COLLIDE\n");
                snake_obj.Move(main_window->DirectionX, main_window->DirectionY);
                //printf("SNAKE MOVE\n");
                main_window->Draw(fruit_obj.PosX, fruit_obj.PosY);
                //printf("DRAW FRUIT\n");
                snake_obj.Draw(main_window->GetSize(), main_window->GetRenderer());
                //printf("snake_obj.Draw\n");
                //printf("scoreX: %d\nscoreY: %d\nsnakeGetSize: %d\n",main_window.scoreX,main_window.scoreY,snake_obj.GetSnakeSize());
                main_window->DrawScore(main_window->scoreX,main_window->scoreY,snake_obj.GetSnakeSize());
                main_window->Refresh();
                if (Collide == 0){
                    //printf("COLLIDE == 0\n");
                    Collide = snake_obj.CheckSnakeCollide();
                    //printf("SNAKE CHECK COLLIDE\n");
                }
                
                /*if(Collide==1){
                    //printf("COLLIDE == 1\n");
                    snake_obj.DeleteSegments();
                    //printf("snake_obj.DeleteSegments()\n");
                    main_window->DirectionX = 0;
                    //printf("window directionX = 0\n");
                    main_window->DirectionY = 0;
                    //printf("window DirectionY = 0\n");

                    main_window->Draw(fruit_obj.PosX, fruit_obj.PosY);
                    //printf("DRAW FRUIT\n");
                    snake_obj.Draw(main_window->GetSize(), main_window->GetRenderer());
                    //printf("Dsnake_obj.Draw\n");
                    main_window->DrawScore(main_window->scoreX,main_window->scoreY,snake_obj.GetSnakeSize());
                    //printf("DRAW SCORE\n");
                    main_window->Refresh();
                    //printf("REFRESH\n");
                    SDL_Delay(1000);
                    //printf("SDL_DELAY\n");
                }*/

                main_window->frameSlower = 0;
                //printf("frameSlower = 0\n");
            }
            main_window->frameSlower ++;
            SDL_Delay(main_window->frame_rate - main_window->frame_time);
		}
    }
    return main_window->Destroy();
}
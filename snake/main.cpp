#include "include/window.hpp"
#include "include/snake.hpp"
#include "include/fruit.hpp"
#include <SDL2/SDL.h>

int main(void){
    Window main_window;
    Snake snake_obj;
    Fruit fruit_obj;
    main_window.New("Snake", 500, 500);
    snake_obj.New();
    fruit_obj.New();

    while(main_window.closeRequest == 0){
        int Size = main_window.GetSize();
        main_window.frame_time_start = SDL_GetTicks();

        SDL_PollEvent(&main_window.event);

        main_window.frame_time = SDL_GetTicks() - main_window.frame_time_start;

        while (SDL_PollEvent(&main_window.event) != 0)
        {
            if (main_window.event.type == SDL_QUIT){
                main_window.closeRequest = 1;
                break;
            }
        }

        if ( main_window.frame_time < main_window.frame_rate )
		{
            main_window.CheckKeys();
            if(main_window.frameSlower >= 12){
                if(fruit_obj.PosX == snake_obj.PosX && fruit_obj.PosY == snake_obj.PosY){
                    fruit_obj.Randomizer();
                }
                snake_obj.CheckCollide(main_window.winWidth, main_window.winHeight, Size);
                snake_obj.Move(main_window.DirectionX, main_window.DirectionY);
                snake_obj.Eat();
                main_window.Draw(snake_obj.PosX, snake_obj.PosY, fruit_obj.PosX, fruit_obj.PosY);
                main_window.Refresh();

                main_window.frameSlower = 0;
            }
            main_window.frameSlower ++;
            SDL_Delay(main_window.frame_rate - main_window.frame_time);
		}
    }

    return main_window.Destroy();
}
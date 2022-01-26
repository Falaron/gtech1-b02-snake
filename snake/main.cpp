#include "include/snake.hpp"
#include "include/window.hpp"
#include <SDL2/SDL.h>

int main(void){
    Window main_window;
    Snake snake;
    main_window.New("Snake", 500, 500);

    while(main_window.closeRequest == 0){

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
            main_window.Draw();
            main_window.Refresh();

            SDL_Delay(main_window.frame_rate - main_window.frame_time);
		}
    }

    return main_window.Destroy();
}
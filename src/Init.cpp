//
// Created by sarcoma on 25/02/18.
//

#include <SDL_video.h>
#include <SDL_system.h>
#include <SDL.h>
#include <iostream>
#include "Init.h"
#include "Logger.h"
#include "Deinit.h"
#include "constants.h"

int Init::sdl(SDL_Window** window, SDL_Renderer** renderer)
{
    {

        if (SDL_Init(SDL_INIT_VIDEO)!=0) {
            Logger::sdlError(std::cout, "SDL_Init Error: ");

            return 1;
        }

        *window = SDL_CreateWindow(SCREEN_TITLE, 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (*window==nullptr) {
            Logger::sdlError(std::cout, "SDL_CreateWindow Error: ");
            SDL_Quit();

            return 1;
        }

        *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (*renderer==nullptr) {
            Logger::sdlError(std::cout, "SDL_CreateRenderer Error: ");
            Deinit::window(*window);
            SDL_Quit();

            return 1;
        }
        return 0;
    }
}

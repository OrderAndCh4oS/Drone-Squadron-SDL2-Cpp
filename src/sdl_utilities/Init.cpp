//
// Created by sarcoma on 25/02/18.
//

#include <SDL_video.h>
#include <SDL_system.h>
#include <SDL.h>
#include <iostream>
#include "Init.h"
#include "../utilities/Logger.h"
#include "Deinit.h"
#include "../constants.h"

int Init::sdl()
{
    {

        if (SDL_Init(SDL_INIT_VIDEO)!=0) {
            Logger::sdlError(std::cout, "SDL_Init Error: ");

            return 1;
        }

        gWindow = SDL_CreateWindow(SCREEN_TITLE, 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow==nullptr) {
            Logger::sdlError(std::cout, "SDL_CreateWindow Error: ");
            SDL_Quit();

            return 1;
        }

        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (gRenderer==nullptr) {
            Logger::sdlError(std::cout, "SDL_CreateRenderer Error: ");
            Deinit::window(gWindow);
            SDL_Quit();

            return 1;
        }
        return 0;
    }
}

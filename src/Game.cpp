//
// Created by sarcoma on 06/03/18.
//

#include <SDL_video.h>
#include <SDL_system.h>
#include "Game.h"
#include "Texture.h"
#include "main.h"
#include "constants.h"

Game::Game(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Game::start(SDL_Window* sdlWindow, SDL_Renderer* sdlRenderer)
{
    std::__cxx11::string imagePath = Texture::path("drone-blue.bmp");
    SDL_Texture* drone = Texture::get(imagePath, sdlWindow, sdlRenderer);
    SDL_RenderClear(sdlRenderer);
    Texture::render(drone, sdlRenderer, SCREEN_WIDTH/2+x, SCREEN_HEIGHT/2+y);
    SDL_RenderPresent(sdlRenderer);
    SDL_Delay(1);
    y -= 5;
}

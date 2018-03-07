//
// Created by sarcoma on 06/03/18.
//

#include "Game.h"

Game::Game(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Game::start()
{
    std::__cxx11::string imagePath = Resource::path("drone-blue.gif");
    auto* drone = new Texture();
    drone->set(imagePath);
    SDL_RenderClear(gRenderer);
    drone->render(SCREEN_WIDTH/2+x, SCREEN_HEIGHT/2+y);
    SDL_RenderPresent(gRenderer);
    SDL_Delay(1);
    drone->free();
    y -= 3;
}



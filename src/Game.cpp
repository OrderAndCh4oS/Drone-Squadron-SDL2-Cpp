//
// Created by sarcoma on 06/03/18.
//

#include "Game.h"

Game::Game(int x, int y)
{
    this->x = x;
    this->y = y;
    drone = new Drone("drone-one", Vector(SCREEN_WIDTH/2, SCREEN_HEIGHT), 245);
}

void Game::start()
{
    SDL_RenderClear(gRenderer);
    drone->draw();
    drone->update();
    SDL_RenderPresent(gRenderer);
}

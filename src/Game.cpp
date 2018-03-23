//
// Created by sarcoma on 06/03/18.
//

#include "Game.h"

Game::Game()
{
    drone = new Drone("drone-one", Vector(SCREEN_WIDTH/2, SCREEN_HEIGHT), 245);
}

void Game::start()
{
    drone->draw();
    drone->update();
}

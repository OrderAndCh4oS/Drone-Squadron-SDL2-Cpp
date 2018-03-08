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
    std::__cxx11::string imagePath = Resource::path("drone-pair.gif");
    auto* drone = new Texture();
    drone->set(imagePath);
    SDL_RenderClear(gRenderer);
    SDL_Rect clip[2];
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].h = drone->getHeight();
    clip[0].w = drone->getWidth()/2;
    clip[1].x = drone->getWidth()/2;
    clip[1].y = 0;
    clip[1].h = drone->getHeight();
    clip[1].w = drone->getWidth()/2;
    drone->render(SCREEN_WIDTH/3+x, SCREEN_HEIGHT/2+y, &clip[0]);
    drone->render(SCREEN_WIDTH/3*2+x, SCREEN_HEIGHT/2+y, &clip[1]);
    SDL_RenderPresent(gRenderer);
    drone->free();
    move += 30*deltaTime->get();
    if (move>=1) {
        y -= floor(move);
        double intPart{};
        move = modf(move, &intPart);
    }
}

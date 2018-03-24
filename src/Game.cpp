//
// Created by sarcoma on 06/03/18.
//

#include "Game.h"

Game::Game()
{
    drone = new Drone("drone-one", Vector(SCREEN_WIDTH/2, SCREEN_HEIGHT), 245);
    gameView = new View{640, 440, 0, 0};
    gameView->setBackgroundColour(0x0, 0x0, 0x25, 0xFF);
    menuView = new View{640, 480, 0, 440};
    menuView->setBackgroundColour(0x25, 0x25, 0x40, 0xFF);
    buttonOne = new TurnLeft{20, 20, 10, 10, drone};
    buttonOne->setBackgroundColour(0x25, 0xC6, 0x25, 0xFF);
    menuView->add(buttonOne);
    buttonTwo = new TurnRight{20, 20, 40, 10, drone};
    buttonTwo->setBackgroundColour(0x25, 0xC6, 0x25, 0xFF);
    menuView->add(buttonTwo);
}

void Game::start()
{
    while (SDL_PollEvent(&e)) {
        if (e.type==SDL_QUIT) {
            quit = true;
        }
        if (e.type==SDL_MOUSEBUTTONUP) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            buttonOne->handleMouseUpEvent(x, y);
            buttonTwo->handleMouseUpEvent(x, y);
        }
    }
    menuView->draw();
    gameView->draw();
    drone->draw();
    drone->update();
}

bool Game::isQuit() const
{
    return quit;
}

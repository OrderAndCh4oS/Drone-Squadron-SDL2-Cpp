//
// Created by sarcoma on 06/03/18.
//

#ifndef SDLTEST_GAME_H
#define SDLTEST_GAME_H

#include <SDL_video.h>
#include <SDL_system.h>
#include "graphics/Texture.h"
#include "main.h"
#include "constants.h"
#include "graphics/Resource.h"
#include "graphics/Drone.h"
#include "buttons/TurnLeft.h"
#include "ui/View.h"
#include "buttons/TurnRight.h"

class Game {
private:
    bool quit{false};
    SDL_Event e{};
    View* gameView;
    View* menuView;
    Drone* drone;
    TurnLeft* buttonOne;
    TurnRight* buttonTwo;

public:

    Game();

    /**
     * Run the game
     */
    void start();

    bool isQuit() const;
};

#endif //SDLTEST_GAME_H

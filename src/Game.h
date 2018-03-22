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

class Game {
private:
    Drone* drone;
public:
    Game();

    /**
     * Run the game
     */
    void start();


};

#endif //SDLTEST_GAME_H

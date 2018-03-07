//
// Created by sarcoma on 06/03/18.
//

#ifndef SDLTEST_GAME_H
#define SDLTEST_GAME_H

#include <SDL_video.h>
#include <SDL_system.h>
#include "Texture.h"
#include "main.h"
#include "constants.h"
#include "Resource.h"

class Game {
private:
    int x{0}, y{0};

public:
    Game(int x, int y);

    /**
     * Run the game
     */
    void start();

};

#endif //SDLTEST_GAME_H

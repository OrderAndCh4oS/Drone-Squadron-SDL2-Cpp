//
// Created by sarcoma on 25/03/18.
//

#ifndef SDLTEST_FPS_H
#define SDLTEST_FPS_H

#include <SDL_events.h>
#include <sstream>

class FPS {
    //Event handler
    SDL_Event e; //Set text color as black
    SDL_Color textColor = {0, 0, 0, 255}; //The frames per second timer
    std::stringstream timeText;
};

#endif //SDLTEST_FPS_H

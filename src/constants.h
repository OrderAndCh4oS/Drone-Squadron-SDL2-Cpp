//
// Created by sarcoma on 25/02/18.
//

#ifndef SDLTEST_CONSTANTS_H
#define SDLTEST_CONSTANTS_H

#include <SDL_video.h>
#include <SDL_system.h>
#include <SDL_timer.h>
#include "utilities/DeltaTime.h"

const char* const SCREEN_TITLE{"Game Window"};
const int SCREEN_WIDTH{640};
const int SCREEN_HEIGHT{480};

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern DeltaTime* deltaTime;

#endif //SDLTEST_CONSTANTS_H

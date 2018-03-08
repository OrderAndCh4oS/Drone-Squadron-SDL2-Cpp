//
// Created by sarcoma on 08/03/18.
//

#ifndef SDLTEST_DELTATIME_H
#define SDLTEST_DELTATIME_H

#include <SDL_quit.h>
#include <SDL_timer.h>

class DeltaTime {
private:
    Uint64 NOW;
    Uint64 LAST;
    double deltaTime;

public:
    DeltaTime();

    void update();

    double get();
};

#endif //SDLTEST_DELTATIME_H

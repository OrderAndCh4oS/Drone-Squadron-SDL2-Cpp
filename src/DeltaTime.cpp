//
// Created by sarcoma on 08/03/18.
//

#include "DeltaTime.h"

DeltaTime::DeltaTime()
{
    NOW = SDL_GetPerformanceCounter();
    LAST = 0;
    deltaTime = 0;
}

void DeltaTime::update()
{
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();

    deltaTime = (double) ((NOW-LAST)*1000/SDL_GetPerformanceFrequency());
}

double DeltaTime::get()
{
    return deltaTime*0.001;
}


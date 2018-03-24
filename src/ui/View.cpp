//
// Created by sarcoma on 24/03/18.
//

#include <SDL_render.h>
#include "View.h"
#include "../constants.h"

View::View(int width, int height, int x, int y)
        :Panel(width, height, x, y)
{
    this->fill = {0, 0, width, height};
}

void View::draw()
{
    SDL_SetRenderDrawColor(gRenderer, colour[0], colour[1], colour[2], colour[3]);
    SDL_RenderSetViewport(gRenderer, &panel);
    SDL_RenderFillRect(gRenderer, &fill);
    Panel::drawChildren();
}

void View::add(Panel* child)
{
    Panel::add(child);
}

void View::setBackgroundColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    Panel::setBackgroundColour(r, g, b, a);
}

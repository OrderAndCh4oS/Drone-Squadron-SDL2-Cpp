//
// Created by sarcoma on 24/03/18.
//

#include <SDL_render.h>
#include "View.h"
#include "../constants.h"

View::View(int width, int height, int x, int y)
        :Panel(width, height, x, y) { }

void View::draw()
{
    SDL_RenderSetViewport(gRenderer, &getPanel());
    Panel::drawChildren();
}

void View::add(Panel* child)
{
    Panel::add(child);
}

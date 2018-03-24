//
// Created by sarcoma on 24/03/18.
//

#include <SDL_rect.h>
#include "Button.h"

Button::Button(int width, int height, int x, int y)
        :Panel(width, height, x, y)
{

}

bool Button::clickIsInButton(int x, int y) const
{
    return x>panel.x && y>panel.y && x<panel.x+panel.w && y>panel.y+panel.h;
}

void Button::handleMouseUpEvent(int x, int y) { }


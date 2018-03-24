//
// Created by sarcoma on 24/03/18.
//

#include <SDL_rect.h>
#include <iostream>
#include "Button.h"
#include "../utilities/Logger.h"

Button::Button(int width, int height, int x, int y)
        :Panel(width, height, x, y)
{

}

void Button::handleMouseUpEvent(int x, int y)
{
    if (x>this->panel.x && y>this->panel.y && x<this->panel.x+this->panel.w && y>this->panel.y+this->panel.h) {
        Logger::message(std::cout, "Mouse Up");
    }
}

void Button::draw()
{
    Panel::draw();
}

void Button::add(Panel* child)
{
    Panel::add(child);
}

void Button::drawChildren() const
{
    Panel::drawChildren();
}

void Button::setBackgroundColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    Panel::setBackgroundColour(r, g, b, a);
}

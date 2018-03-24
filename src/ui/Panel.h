//
// Created by sarcoma on 22/03/18.
//

#ifndef SDLTEST_PANEL_H
#define SDLTEST_PANEL_H

#include <SDL_quit.h>
#include <SDL_rect.h>
#include <vector>

class Panel {
protected:
    SDL_Rect panel{};

    std::vector<Panel*> children;

    Uint8 colour[4] = {0x0, 0xFF, 0x0, 0xFF};

public:
    Panel(int width, int height, int x, int y);

    virtual void draw();

    virtual void add(Panel* child);

    virtual void drawChildren() const;

    virtual void setBackgroundColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

#endif //SDLTEST_PANEL_H

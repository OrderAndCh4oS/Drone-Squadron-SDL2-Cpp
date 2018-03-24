//
// Created by sarcoma on 24/03/18.
//

#ifndef SDLTEST_VIEW_H
#define SDLTEST_VIEW_H

#include <SDL_rect.h>
#include "Panel.h"

class View : Panel {
private:
    SDL_Rect fill{};
public:
    View(int width, int height, int x, int y);

    void draw() override;

    void add(Panel* child) override;

    void setBackgroundColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a) override;

};

#endif //SDLTEST_VIEW_H

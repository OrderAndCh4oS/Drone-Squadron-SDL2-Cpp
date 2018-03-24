//
// Created by sarcoma on 24/03/18.
//

#ifndef SDLTEST_BUTTON_H
#define SDLTEST_BUTTON_H

#include "Panel.h"

class Button : public Panel {
public:
    Button(int width, int height, int x, int y);

    void handleMouseUpEvent(int x, int y);
};

#endif //SDLTEST_BUTTON_H

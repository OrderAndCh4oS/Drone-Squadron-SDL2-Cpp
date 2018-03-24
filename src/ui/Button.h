//
// Created by sarcoma on 24/03/18.
//

#ifndef SDLTEST_BUTTON_H
#define SDLTEST_BUTTON_H

#include "Panel.h"

class Button : public Panel {
public:
    Button(int width, int height, int x, int y);

    virtual void handleMouseUpEvent(int x, int y);

    bool clickIsInButton(int x, int y) const;
};

#endif //SDLTEST_BUTTON_H

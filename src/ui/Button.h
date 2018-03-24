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

    void draw() override;

    void add(Panel* child) override;

    void drawChildren() const override;

    void setBackgroundColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a) override;
};

#endif //SDLTEST_BUTTON_H

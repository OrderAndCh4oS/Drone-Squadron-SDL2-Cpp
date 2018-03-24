//
// Created by sarcoma on 24/03/18.
//

#ifndef SDLTEST_TURNLEFT_H
#define SDLTEST_TURNLEFT_H

#include "../ui/Button.h"
#include "../graphics/Drone.h"

class TurnLeft : public Button {

private:
    Drone* drone;
public:
    TurnLeft(int width, int height, int x, int y, Drone* drone);

    void handleMouseUpEvent(int x, int y) override;
};

#endif //SDLTEST_TURNLEFT_H

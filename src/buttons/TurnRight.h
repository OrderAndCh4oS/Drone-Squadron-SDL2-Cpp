//
// Created by sarcoma on 24/03/18.
//

#ifndef SDLTEST_TURNRIGHT_H
#define SDLTEST_TURNRIGHT_H

#include "../ui/Button.h"
#include "../graphics/Drone.h"

class TurnRight : public Button {
private:
    Drone* drone;
public:
    TurnRight(int width, int height, int x, int y, Drone* drone);

    void handleMouseUpEvent(int x, int y) override;

};

#endif //SDLTEST_TURNRIGHT_H

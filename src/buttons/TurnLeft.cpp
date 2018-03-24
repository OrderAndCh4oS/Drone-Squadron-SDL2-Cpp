//
// Created by sarcoma on 24/03/18.
//

#include "TurnLeft.h"

TurnLeft::TurnLeft(int width, int height, int x, int y, Drone* drone)
        :Button(width, height, x, y), drone(drone)
{
}

void TurnLeft::handleMouseUpEvent(int x, int y)
{
    if (clickIsInButton(x, y)) {
        drone->turnLeft();
    }
}

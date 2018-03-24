//
// Created by sarcoma on 24/03/18.
//

#include "TurnRight.h"

TurnRight::TurnRight(int width, int height, int x, int y, Drone* drone)
        :Button(width, height, x, y), drone(drone) { }

void TurnRight::handleMouseUpEvent(int x, int y)
{
    if (clickIsInButton(x, y)) {
        drone->turnRight();
    }
}

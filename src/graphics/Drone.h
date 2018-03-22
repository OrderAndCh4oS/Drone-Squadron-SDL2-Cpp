//
// Created by sarcoma on 17/03/18.
//

#ifndef SDLTEST_DRONE_H
#define SDLTEST_DRONE_H

#include "Particle.h"

class Drone : protected Particle {
public:
    Drone(const std::string& id, const Vector& position, double degrees);

    void update() override;

    void draw() override;
};

#endif //SDLTEST_DRONE_H

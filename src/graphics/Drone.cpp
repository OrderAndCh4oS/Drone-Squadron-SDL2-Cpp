//
// Created by sarcoma on 17/03/18.
//

#include <iostream>
#include "Drone.h"
#include "Resource.h"
#include "../constants.h"

Drone::Drone(const std::string& id, const Vector& position, double degrees)
        :Particle(id, position, degrees)
{
    std::__cxx11::string imagePath = Resource::path("drone-blue.gif");
    texture->set(imagePath);
    velocity->setLength(100);
    velocity->setAngle(angle.getRadians());
}

void Drone::update()
{
    position.addTo(velocity->multiply(deltaTime->get()));
}

void Drone::draw()
{
    texture->render((int) round(position.getX()), (int) round(position.getY()), nullptr, angle.getDegrees());
}

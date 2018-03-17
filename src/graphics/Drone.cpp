//
// Created by sarcoma on 17/03/18.
//

#include <iostream>
#include "Drone.h"
#include "../utilities/Logger.h"
#include "Resource.h"
#include "../constants.h"

Drone::Drone(const std::string& id, const Vector& position)
        :Particle(id, position)
{
    std::__cxx11::string imagePath = Resource::path("drone-blue.gif");
    texture->set(imagePath);
    velocity->setLength(100);
    velocity->setAngle(-3.14/2);
}

void Drone::update()
{
    ;
    position.addTo(velocity->multiply(deltaTime->get()));
    Logger::message(std::cout, "update");
}

void Drone::draw()
{
    texture->render(position.getX(), position.getY());
    Logger::message(std::cout, "draw");
}

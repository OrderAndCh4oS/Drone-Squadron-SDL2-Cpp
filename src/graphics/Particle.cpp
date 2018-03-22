//
// Created by sarcoma on 17/03/18.
//

#include "Particle.h"

Particle::Particle(const std::string& id, const Vector& position, double degrees)
        :GameObject(id, position)
{
    this->angle.setDegrees(degrees);
    texture = new Texture();
    velocity = new Vector(0, 0);
}

Vector* Particle::getVelocity() const
{
    return velocity;
}

//
// Created by sarcoma on 17/03/18.
//

#include "Particle.h"

Particle::Particle(const std::string& id, const Vector& position, double angle)
        :GameObject(id, position), angle(angle)
{
    texture = new Texture();
    velocity = new Vector(0, 0);
}

Vector* Particle::getVelocity() const
{
    return velocity;
}

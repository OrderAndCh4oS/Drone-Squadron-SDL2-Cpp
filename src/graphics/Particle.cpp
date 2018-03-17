//
// Created by sarcoma on 17/03/18.
//

#include "Particle.h"

Particle::Particle(const std::string& id, const Vector& position)
        :GameObject(id, position)
{
    texture = new Texture();
    velocity = new Vector(0, 0);
}

Vector* Particle::getVelocity() const
{
    return velocity;
}

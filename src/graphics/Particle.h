//
// Created by sarcoma on 17/03/18.
//

#ifndef SDLTEST_PARTICLE_H
#define SDLTEST_PARTICLE_H

#include <SDL_render.h>
#include "GameObject.h"
#include "Texture.h"

class Particle : protected GameObject {
protected:
    Vector* velocity;
    double angle{0};
    Texture* texture = nullptr;
    SDL_Rect clip;
public:
    Particle(const std::string& id, const Vector& position, double angle);

    Vector* getVelocity() const;

    virtual void draw()= 0;
};

#endif //SDLTEST_PARTICLE_H

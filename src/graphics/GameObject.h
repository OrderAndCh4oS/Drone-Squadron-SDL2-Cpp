//
// Created by sarcoma on 17/03/18.
//

#ifndef SDLTEST_GAMEOBJECT_H
#define SDLTEST_GAMEOBJECT_H

#include <string>
#include "../geometry/Vector.h"

class GameObject {
protected:
    std::string id{};
    Vector position;
public:
    GameObject(std::string id, Vector position);

    const std::string& getId() const;

    const Vector& getPosition() const;

    virtual void update()= 0;

};

#endif //SDLTEST_GAMEOBJECT_H

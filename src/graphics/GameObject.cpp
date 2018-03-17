//
// Created by sarcoma on 17/03/18.
//

#include "GameObject.h"

GameObject::GameObject(const std::string id, Vector position)
        :id(id), position(position) { }

const std::string& GameObject::getId() const
{
    return id;
}

const Vector& GameObject::getPosition() const
{
    return position;
}

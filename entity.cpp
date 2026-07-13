#include "Entity.h"

Entity::Entity() {
    name = "Unknown Entity";
}

Entity::Entity(std::string n) {
    name = n;
}

std::string Entity::getName() {
    return name;
}

void Entity::setName(std::string n) {
    name = n;
}
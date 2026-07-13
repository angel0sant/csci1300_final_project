#ifndef ENTITY_H
#define ENTITY_H
#include <string>

class Entity {
protected:
    std::string name;
public:
    Entity();
    Entity(std::string n);
    std::string getName();
    void setName(std::string n);
};
#endif
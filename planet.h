#ifndef PLANET_H
#define PLANET_H
#include "Entity.h"

class Planet : public Entity {
private:
    int energy;
    int water;
    int temperature;
    int atmosphere;
public:
    Planet();
    Planet(std::string n);
    void displayStats();
    void modifyEnergy(int amount);
    int getEnergy();
};
#endif
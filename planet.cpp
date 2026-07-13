#include "Planet.h"
#include <iostream>

Planet::Planet() : Entity("Barren Planet") {
    energy = 100;
    water = 0;
    temperature = -50;
    atmosphere = 0;
}

Planet::Planet(std::string n) : Entity(n) {
    energy = 100;
    water = 0;
    temperature = -50;
    atmosphere = 0;
}

void Planet::displayStats() {
    std::cout << "Planet: " << name << "\n";
    std::cout << "Energy (Cosmic Energy): " << energy << "\n";
    std::cout << "Water: " << water << " | Temp: " << temperature << " | Atmos: " << atmosphere << "\n";
}

void Planet::modifyEnergy(int amount) {
    energy += amount;
}

int Planet::getEnergy() {
    return energy;
}
#ifndef PLANET_H
#define PLANET_H
#include "Entity.h"
#include "Item.h"
#include <string>

using namespace std;

class Planet : public Entity {
private:
    int energy;
    int water;
    int temperature;
    int atmosphere;
    
    Item inventory[5]; 
    int inventory_count;
    
public:
    Planet();
    Planet(string n);
    void displayStats();
    
    void modifyEnergy(int amount);
    void modifyWater(int amount);
    void modifyTemperature(int amount);
    void modifyAtmosphere(int amount);
    
    int getEnergy();
    int getWater();
    int getTemperature();
    int getAtmosphere();
    
    bool addItem(Item new_item);
    void displayInventory();
    bool hasItem(string item_name);
    int getInventoryCount();
};
#endif
#include "Planet.h"
#include <iostream>

using namespace std;

Planet::Planet() : Entity("Barren Planet") {
    energy = 100;
    water = 0;
    temperature = -50;
    atmosphere = 0;
    inventory_count = 0;
}

Planet::Planet(string n) : Entity(n) {
    energy = 100;
    water = 0;
    temperature = -50;
    atmosphere = 0;
    inventory_count = 0;
}

void Planet::displayStats() {
    cout<<"+++++++++++++++++++++++++++"<<endl;
    cout<<"   PLANETARY CORE STATS"<<endl;
    cout<<"+++++++++++++++++++++++++++"<<endl;
    cout<<"Planet: "<<name<<endl;
    cout<<"Energy: "<<energy<<endl;
    cout<<"Water: "<<water<<" | Temp: "<<temperature<<"C | Atmos: "<<atmosphere<<"%"<<endl;
}

void Planet::modifyEnergy(int amount) { energy += amount; }
void Planet::modifyWater(int amount) { water += amount; }
void Planet::modifyTemperature(int amount) { temperature += amount; }
void Planet::modifyAtmosphere(int amount) { atmosphere += amount; }

int Planet::getEnergy() { return energy; }
int Planet::getWater() { return water; }
int Planet::getTemperature() { return temperature; }
int Planet::getAtmosphere() { return atmosphere; }

bool Planet::addItem(Item new_item) {
    if(inventory_count < 5) {
        inventory[inventory_count] = new_item;
        inventory_count++;
        return true;
    }
    return false;
}

void Planet::displayInventory() {
    cout<<"--- Current Inventory ---"<<endl;
    if(inventory_count == 0) {
        cout<<"Inventory is empty."<<endl;
    } else {
        for(int i = 0; i < inventory_count; i++) {
            inventory[i].displayItem();
        }
    }
}

bool Planet::hasItem(string item_name) {
    for(int i = 0; i < inventory_count; i++) {
        if(inventory[i].getName() == item_name) {
            return true;
        }
    }
    return false;
}

int Planet::getInventoryCount() {
    return inventory_count;
}


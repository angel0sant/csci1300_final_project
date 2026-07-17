#ifndef SECTOR_H
#define SECTOR_H
#include <string>
#include "NPCPlanet.h"
#include "Item.h"

using namespace std;

class Sector {
private:
    string sector_name;
    string sector_description;
    NPCPlanet sector_npc;
    Item sector_item;
    bool has_npc;
    bool has_item;
    
public:
    Sector();
    Sector(string name, string desc);
    Sector(string name, string desc, NPCPlanet npc, Item item);
    
    string getName();
    string getDescription();
    
    void setNPC(NPCPlanet npc);
    NPCPlanet getNPC();
    bool hasNPC();
    
    void setItem(Item item);
    Item searchItem();
    bool hasItem();
    
    void displaySector();
};
#endif

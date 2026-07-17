#include "Sector.h"
#include <iostream>
using namespace std;

Sector::Sector() {
    sector_name = "Unknown Sector";
    sector_description = "Empty space.";
    has_npc = false;
    has_item = false;
}

Sector::Sector(string name, string desc) {
    sector_name = name;
    sector_description = desc;
    has_npc = false;
    has_item = false;
}

Sector::Sector(string name, string desc, NPCPlanet npc, Item item) {
    sector_name = name;
    sector_description = desc;
    sector_npc = npc;
    sector_item = item;
    has_npc = true;
    has_item = true;
}

string Sector::getName() { 
    return sector_name; 
}

string Sector::getDescription() { 
    return sector_description; 
}

void Sector::setNPC(NPCPlanet npc) {
    sector_npc = npc;
    has_npc = true;
}

NPCPlanet Sector::getNPC() { 
    return sector_npc; 
}

bool Sector::hasNPC() { 
    return has_npc; 
}

void Sector::setItem(Item item) {
    sector_item = item;
    has_item = true;
}

Item Sector::searchItem() {
    has_item = false; 
    return sector_item;
}

bool Sector::hasItem() { 
    return has_item; 
}

void Sector::displaySector() {
    cout<<"+++++++++++++++++++++++++++"<<endl;
    cout<<"   SYSTEM SCANNER DATA"<<endl;
    cout<<"+++++++++++++++++++++++++++"<<endl;
    cout<<"Sector: "<<sector_name<<endl;
    cout<<"Details: "<<sector_description<<endl;
    if(has_npc) {
        cout<<"Lifeform Detected: "<<sector_npc.getName()<<endl;
    }
    if(has_item) {
        cout<<"Resource Detected: Unknown material available for extraction."<<endl;
    }
    cout<<"==========================="<<endl;
}

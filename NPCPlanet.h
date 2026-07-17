#ifndef NPCPLANET_H
#define NPCPLANET_H
#include "Entity.h"
#include "Item.h"
#include <string>

using namespace std;

class NPCPlanet : public Entity {
private:
    string planet_dialogue;
    Item reward_item;
    bool quest_completed;
public:
    NPCPlanet();
    NPCPlanet(string n, string d, Item r);
    void interact();
    Item getReward();
    bool isQuestCompleted();
    void completeQuest();
};
#endif
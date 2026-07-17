#include "NPCPlanet.h"
#include <iostream>

using namespace std;

NPCPlanet::NPCPlanet() : Entity("Unknown Celestial") {
    planet_dialogue = "...";
    quest_completed = false;
}

NPCPlanet::NPCPlanet(string n, string d, Item r) : Entity(n) {
    planet_dialogue = d;
    reward_item = r;
    quest_completed = false;
}

void NPCPlanet::interact() {
    cout<<endl<<"["<<name<<" transmits a signal]:"<<endl;
    cout<<"\""<<planet_dialogue<<"\""<<endl;
}

Item NPCPlanet::getReward() {
    return reward_item;
}

bool NPCPlanet::isQuestCompleted() {
    return quest_completed;
}

void NPCPlanet::completeQuest() {
    quest_completed = true;
}
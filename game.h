#ifndef GAME_H
#define GAME_H
#include "Planet.h"
#include <string>

class Game {
private:
    Planet playerPlanet;
    int epochsLeft;
    std::string loadedEvents[10];
    int numEvents;
public:
    Game();
    void loadEventsFromFile(std::string filename);
    void run();
};
#endif
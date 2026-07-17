#ifndef GAME_H
#define GAME_H
#include "Planet.h"
#include "Sector.h"
#include <string>

using namespace std;

class Game {
private:
    Planet player_planet;
    Sector galaxy_map[4];
    int current_sector;
    int epochs_left;
    
    string loaded_events[10];
    int loaded_effects[10];
    int num_events;
    
    int corruption_level;
    
public:
    Game();
    void loadEventsFromFile(string filename);
    void setupUniverse();
    
    void displayDashboard();
    void displayMap();
    
    void movePlayer();
    void searchArea();
    void talkToCharacter();
    void visitMerchant();
    void triggerRandomEvent();
    
    bool checkWinCondition();
    bool checkLossCondition();
    
    void run();
};
#endif
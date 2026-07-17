#include "Game.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game() {
    player_planet = Planet("Kepler-452b");
    epochs_left = 15; // the time limit for game
    current_sector = 0;
    num_events = 0;
    corruption_level = 0;
    srand(time(0));
}

void Game::loadEventsFromFile(string filename) {
    ifstream file(filename);
    string event_name;
    int effect;
    
    if (file.is_open()) {
        while (file >> event_name >> effect && num_events < 10) {
            loaded_events[num_events] = event_name;
            loaded_effects[num_events] = effect;
            num_events++;
        }
        file.close();
    }
}

void Game::setupUniverse() {
    Item hydrogen("Hydrogen", "Gas");
    Item silicate("Silicate", "Mineral");
    Item nitrogen("Nitrogen", "Gas");
    Item water_reward("Liquid Water", "Liquid");
    Item carbon_reward("Carbon", "Element");
    Item shady_item("Smuggled Element", "Black Market");
    
    NPCPlanet terra("Terra", "I sense you are building an atmosphere. Gather gases from the nebulas, but watch your energy!", Item());
    NPCPlanet glacio("Glacio", "It is so cold... If you give me 20 Energy to warm my core, I will share my Liquid Water.", water_reward);
    NPCPlanet vulcan("Vulcan", "BURN! If your temperature is 50C or higher, I will respect you and give you Carbon!", carbon_reward);
    NPCPlanet merchant("Asteroid Merchant", "I have what you need to survive. It will just cost you 30 Energy... permanently.", shady_item);
    
    galaxy_map[0] = Sector("Nursery Nebula", "A calm, gaseous cloud.", terra, hydrogen);
    galaxy_map[1] = Sector("Ice Dwarf System", "Freezing and desolate.", glacio, silicate);
    galaxy_map[2] = Sector("Red Giant System", "Dangerously hot.", vulcan, nitrogen);
    galaxy_map[3] = Sector("Asteroid Belt", "A shady trading hub.", merchant, Item());
}

void Game::displayDashboard() {
    cout<<endl<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"            THE FINAL BUNDLE: SPACE EPOCH         "<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Epochs Remaining: "<<epochs_left<<" | Corruption: "<<corruption_level<<endl;
    player_planet.displayStats();
    cout<<"Bundle Progress: "<<player_planet.getInventoryCount()<<" / 5 Items Donated"<<endl;
    player_planet.displayInventory();
    cout<<"=================================================="<<endl;
}

void Game::displayMap() {
    cout<<endl<<"--- WARP GATE NETWORK ---"<<endl;
    string s0 = (current_sector == 0) ? "[*Nursery Nebula*]" : "[Nursery Nebula]";
    string s1 = (current_sector == 1) ? "[*Ice Dwarf*]" : "[Ice Dwarf]";
    string s2 = (current_sector == 2) ? "[*Red Giant*]" : "[Red Giant]";
    string s3 = (current_sector == 3) ? "[*Asteroid Belt*]" : "[Asteroid Belt]";
    
    cout<<"       "<<s1<<endl;
    cout<<"           |"<<endl;
    cout<<" "<<s0<<" -- "<<s3<<endl;
    cout<<"           |"<<endl;
    cout<<"       "<<s2<<endl;
    cout<<"(* = You are here)"<<endl;
}

void Game::movePlayer() {
    displayMap();
    cout<<"Enter Sector ID to warp (0: Nebula, 1: Ice Dwarf, 2: Red Giant, 3: Asteroid Belt): ";
    int choice;
    cin>>choice;
    if(choice >= 0 && choice <= 3) {
        current_sector = choice;
        player_planet.modifyEnergy(-5);
        cout<<"Warp successful! Arrived at "<<galaxy_map[current_sector].getName()<<endl;
    } else {
        cout<<"Invalid coordinates."<<endl;
    }
}

void Game::searchArea() {
    if(galaxy_map[current_sector].hasItem()) {
        Item found = galaxy_map[current_sector].searchItem();
        player_planet.addItem(found);
        cout<<"Success! You extracted "<<found.getName()<<" from the sector."<<endl;
    } else {
        cout<<"You scanned the sector, but found no extractable resources."<<endl;
    }
}

void Game::talkToCharacter() {
    if(!galaxy_map[current_sector].hasNPC()) {
        cout<<"No signals detected in this sector."<<endl;
        return;
    }
    
    NPCPlanet npc = galaxy_map[current_sector].getNPC();
    npc.interact();
    string npc_name = npc.getName();
    
    //logic for quests
    if(npc_name == "Glacio" && !npc.isQuestCompleted()) {
        cout<<"Give Glacio 20 Energy for Liquid Water? (1 for Yes, 2 for No): ";
        int choice;
        cin>>choice;
        if(choice == 1) {
            if(player_planet.getEnergy() >= 20) {
                player_planet.modifyEnergy(-20);
                player_planet.addItem(npc.getReward());
                cout<<"You received Liquid Water!"<<endl;
                npc.completeQuest();
                galaxy_map[current_sector].setNPC(npc);
            } else {
                cout<<"Not enough energy!"<<endl;
            }
        }
    } 
    else if (npc_name == "Vulcan" && !npc.isQuestCompleted()) {
        if(player_planet.getTemperature() >= 50) {
            cout<<"Vulcan respects your heat! You received Carbon!"<<endl;
            player_planet.addItem(npc.getReward());
            npc.completeQuest();
            galaxy_map[current_sector].setNPC(npc);
        } else {
            cout<<"Vulcan ignores you. You are too cold. (Need 50C Temp)"<<endl;
        }
    }
    else if (npc_name == "Asteroid Merchant") {
        visitMerchant();
    }
}

void Game::visitMerchant() {
    cout<<"--- ASTEROID MERCHANT ---"<<endl;
    cout<<"1. Buy missing bundle item (Costs 30 Energy permanently)"<<endl;
    cout<<"2. Leave"<<endl;
    int choice;
    cin>>choice;
    if(choice == 1) {
        if(player_planet.getEnergy() > 30) {
            Item shady_item("Smuggled Element", "Black Market");
            player_planet.modifyEnergy(-30);
            player_planet.addItem(shady_item);
            corruption_level++;
            cout<<"You feel your core weaken, but you got the item."<<endl;
        } else {
            cout<<"You don't have enough energy to survive this trade."<<endl;
        }
    }
}

void Game::triggerRandomEvent() {
    if(num_events > 0) {
        int rand_index = rand() % num_events;
        cout<<endl<<"=== COSMIC EVENT ==="<<endl;
        cout<<loaded_events[rand_index]<<" swept through the system!"<<endl;
        player_planet.modifyEnergy(loaded_effects[rand_index]);
    }
}

bool Game::checkWinCondition() {
    if(player_planet.getInventoryCount() >= 5) { return true; }
    return false;
}

bool Game::checkLossCondition() {
    if(epochs_left <= 0 || player_planet.getEnergy() <= 0) { return true; }
    return false;
}

void Game::run() {
    loadEventsFromFile("events.txt");
    setupUniverse();
    int choice = 0;
    
    while(true) {
        if(checkLossCondition()) {
            cout<<endl<<"=== GAME OVER :( ==="<<endl;
            cout<<"Your planet's core died out before habitability could be reached..."<<endl;
            break;
        }
        if(checkWinCondition()) {
            cout<<endl<<"=== VICTORY :D ==="<<endl;
            if(corruption_level > 0) {
                cout<<"You completed the bundle, but at a terrible cost."<<endl;
                cout<<"The dark matter syndicate now owns your orbit."<<endl; // joja kind of ending
            } else {
                cout<<"You successfully built a habitable world through cosmic balance!"<<endl;
                cout<<"Life begins to bloom on "<<player_planet.getName()<<"!"<<endl; //community ending
            }
            break;
        }
        
        displayDashboard();
        cout<<"1. Search Sector for Resources"<<endl;
        cout<<"2. Talk to Celestial Being"<<endl;
        cout<<"3. Trigger Volcanic Eruption (Cost: 10 Energy, +50 Temp)"<<endl;
        cout<<"4. Warp to New Sector (Cost: 5 Energy)"<<endl;
        cout<<"5. End Epoch (Pass Time)"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        
        if(choice == 1) { searchArea(); } 
        else if (choice == 2) { talkToCharacter(); } 
        else if (choice == 3) {
            player_planet.modifyTemperature(50);
            player_planet.modifyAtmosphere(10);
            player_planet.modifyEnergy(-10);
            cout<<"Massive eruptions! Temperature rising..."<<endl;
        } 
        else if (choice == 4) { movePlayer(); } 
        else if (choice == 5) {
            epochs_left--;
            triggerRandomEvent();
        } 
        else { cout<<"Invalid choice."<<endl; }
    }
}

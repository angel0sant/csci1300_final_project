// --- Game.cpp ---
#include "Game.h"
#include <iostream>
#include <fstream>

Game::Game() {
    playerPlanet = Planet("Kepler-452b");
    epochsLeft = 10;
    numEvents = 0;
}

void Game::loadEventsFromFile(std::string filename) {
    std::ifstream file(filename);
    std::string eventName;
    int effect;
    
    if (file.is_open()) {
        while (file >> eventName >> effect && numEvents < 10) {
            loadedEvents[numEvents] = eventName;
            numEvents++;
        }
        file.close();
        std::cout << "Successfully loaded " << numEvents << " cosmic events from data link.\n";
    } else {
        std::cout << "Error: Could not open " << filename << "\n";
    }
}

void Game::run() {
    loadEventsFromFile("events.txt");
    int choice = 0;

    while (epochsLeft > 0 && playerPlanet.getEnergy() > 0) {
        std::cout << "\n==================================================\n";
        std::cout << "            THE FINAL BUNDLE: SPACE EPOCH         \n";
        std::cout << "==================================================\n";
        std::cout << "Epochs Remaining: " << epochsLeft << "\n";
        playerPlanet.displayStats();
        
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Pull Resource into Orbit (Costs 10 Energy)\n";
        std::cout << "2. Trigger Internal Change (Volcanic Eruption)\n";
        std::cout << "3. View Local Space Map\n";
        std::cout << "4. End Epoch (Pass Time)\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "You pulled an Ice Comet! Water increased, Temp dropped.\n";
            playerPlanet.modifyEnergy(-10);
        } else if (choice == 2) {
            std::cout << "Volcanic Eruption triggered! Atmosphere built, Temp raised.\n";
            playerPlanet.modifyEnergy(-15);
        } else if (choice == 3) {
            std::cout << "[Star] -- [Asteroid Belt] -- [*You*] -- [Comet Cloud]\n";
        } else if (choice == 4) {
            std::cout << "A million years pass...\n";
            epochsLeft--;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
    
    std::cout << "\nGame Over! Time ran out or energy depleted.\n";
}
//
// Created by Ladislav Davídek on 05.11.2021.
//

#include "Game.h"

void Game::init() {
    start();
    this->round++;
    
    Generate g; Person player;
    g.player(&player);
    player.name = player.getName();
    std::cout << "GAME: Welcome, " + player.name << std::endl;
     
    Item weapon = weapon.createItem('w', "Long sword", 0, 0, 20);
    Item weapon2 = weapon2.createItem('w', "Short sword", 0, 0, 15);
    Item weapon3 = weapon3.createItem('w', "Dagger", 0, 0, 10);
    Item weapon4 = weapon4.createItem('w', "Knife", 0, 0, 5);
    Item armor = armor.createItem('a', "Leather vest", 0, 1, 0);
    Item armor2 = armor2.createItem('a', "Chain vest", 0, 10, 0);
    Item emptyWeapon = emptyWeapon.createItem('w', "", 0, 0, 0);
    Item emptyArmor = emptyArmor.createItem('a', "", 0, 0, 0);

    Location emptyLocation;
    emptyLocation.name = "";
    emptyLocation.description = "";

    Location testForrest;
    testForrest.name = "Forrest";
    testForrest.description = "Looks like an ordinady forrest, without trees, made specifically for testing purpose.";
    testForrest.items.push_back(&weapon2);

    Location testCave;
    testCave.name = "Cave";
    testCave.description = "Looks like an ordinady cave, without rocks, made specifically for testing purpose.";
    testCave.items.push_back(&weapon2);
    testCave.items.push_back(&armor);

    Location testRiver;
    testRiver.name = "River";
    testRiver.description = "Looks like an ordinady river, without rocks, made specifically for testing purpose.";

    Location testCity;
    testCity.name = "City";
    testCity.description = "Looks like an ordinady city, without rocks, made specifically for testing purpose.";

    Location testHill;
    testHill.name = "Hill";
    testHill.description = "Looks like an ordinady hill, without rocks, made specifically for testing purpose.";

    testCave.locations.insert({ "north", &testForrest });
    testCave.locations.insert({ "east", &emptyLocation });
    testCave.locations.insert({ "south", &emptyLocation });
    testCave.locations.insert({ "west", &emptyLocation });

    testForrest.locations.insert({ "north", &testHill });
    testForrest.locations.insert({ "west", &testRiver });
    testForrest.locations.insert({ "south", &testCave });
    testForrest.locations.insert({ "east", &testCity });

    player.activeArmor = &emptyArmor;
    player.activeWeapon = &emptyWeapon;
    player.location = &testCave;

    player.inventory.push_back(&weapon3);
    player.inventory.push_back(&weapon4);
    player.inventory.push_back(&armor2);

    while (this->isRunning) {
        std::cout << "GAME: Whats your next step?" << std::endl;
        std::cout << "HERO: ";
        std::string cmd;
        std::getline(std::cin, cmd);
        std::cout << std::endl;

        this->cmdHandler.handle(&player, cmd);

        if (cmd == "q") {
            stop();
        }

        std::cout << std::endl;
    }
}

void Game::start() {
    this->isRunning = true;
}

void Game::stop() {
    this->isRunning = false;
}

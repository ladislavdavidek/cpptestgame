//
// Created by Ladislav Davídek on 05.11.2021.
//

#include "Game.h"

void Game::init() {
    start();
    this->round++;
    
    Person player;
    player.createPlayer(&player);
    //player.name = player.getName();
    //std::cout << "GAME: Welcome, " + player.name << std::endl;


    Item emptyWeapon; emptyWeapon.modifyItem(&emptyWeapon, 'e', false, false, "", "", 0, 0, 0);
    Item emptyArmor; emptyArmor.modifyItem(&emptyArmor, 'e', false, false, "", "", 0, 0, 0);
    Item emptyShield; emptyShield.modifyItem(&emptyShield, 'e', false, false, "", "", 0, 0, 0);
     
    Item weapon2; weapon2.modifyItem(&weapon2, 'w', true, false, "Long Iron sword", "Common", 0, 0, 20);
    Item weapon3; weapon3.modifyItem(&weapon3, 'w', true, false, "Iron Dagger", "Common", 0, 0, 20);
    Item weapon4; weapon4.modifyItem(&weapon4, 'w', true, false, "Fork", "Common", 0, 0, 20);

    Item weapon; weapon.modifyItem(&weapon, 'w', true, false, "Short Iron sword", "Common", 0, 0, 3);
    Item armor; armor.modifyItem(&armor, 'a', true, false, "Leather vest", "Common", 0, 2, 0);
    Item armor2; armor2.modifyItem(&armor2, 'a', true, false, "Chain mail", "Common", 0, 5, 0);

    Item shield1; shield1.modifyItem(&shield1, 's', false, false, "Iron shield", "Common iron shield", 0, 5, 0);

    Item key; key.modifyItem(&key, 'k', true, false, "Rusty key", "Common", 0, 0, 0);

    Location emptyLocation;
    emptyLocation.name = "";
    emptyLocation.description = "";

    Location testLoc2;
    testLoc2.name = "Location 2";
    testLoc2.description = "TEST - LOC 2";

    Location testLoc1;
    testLoc1.name = "Location 1";
    testLoc1.description = "You are in dark cave. Small holes are letting some light inside.";
    testLoc1.items.push_back(&weapon);
    //testLoc1.items.push_back(&weapon2);
    testLoc1.items.push_back(&armor);
    //testLoc1.items.push_back(&shield1);

    Location testLoc5;
    testLoc5.name = "Location 5";
    testLoc5.description = "TEST - LOC 5";

    Location testLoc4;
    testLoc4.name = "Location 4";
    testLoc4.description = "TEST - LOC 4";

    Location testLoc3;
    testLoc3.name = "Location 3";
    testLoc3.description = "TEST - LOC 3";
    testLoc3.items.clear();
    testLoc3.locations.clear();

    testLoc1.locations.push_back(&testLoc2);
    testLoc1.locations.push_back(&emptyLocation);
    testLoc1.locations.push_back(&emptyLocation);
    testLoc1.locations.push_back(&emptyLocation);

    testLoc2.locations.push_back(&testLoc3);
    testLoc2.locations.push_back(&testLoc5);
    testLoc2.locations.push_back(&testLoc1);
    testLoc2.locations.push_back(&testLoc4);

    player.activeArmor = &emptyArmor;
    player.activeWeapon = &emptyWeapon;
    player.activeShield = &emptyShield;
    player.location = &testLoc1;

    //comment out for take all testing
    player.equippedItems.clear();
    player.inventory.clear();
    /*
        .push_back(&weapon3);
    player.inventory.push_back(&weapon4);
    player.inventory.push_back(&armor2);
    player.inventory.push_back(&key);
    */

    std::cout << player.location->description + "\n" << std::endl;

    while (this->isRunning && player.health > 0) {
        std::cout << ">> ";
        std::string cmd;
        std::getline(std::cin, cmd);
        std::cout << std::endl;

        if (cmd == "q") { stop(); break; }
        if (cmd == "v") { save(); }

        this->cmdHandler.handle(&player, cmd);

        std::cout << std::endl;
    }

    if (player.health <= 0) {
        std::cout << "You died.." << std::endl;
    }

    std::cout << "Press any key to end the game." << std::endl;
    std::cin;
}

void Game::start() {
    this->isRunning = true;
}

void Game::stop() {
    this->isRunning = false;
}

void Game::save() {
    std::cout << "Saving not implemented yet." << std::endl;
}

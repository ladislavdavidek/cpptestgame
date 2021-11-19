//
// Created by Ladislav Davídek on 13.11.2021.
//

#include <iostream>
#include <ostream>
#include "Mob.h"
#include "CommandHandler.h"


void CommandHandler::handle(Person* playerInstance, std::string command) {
    std::string cmd = command;

    if (cmd == "equipW") {
        playerInstance->equipItem(playerInstance->inventory[0]);
    }

    if (cmd == "equipA") {
        playerInstance->equipItem(playerInstance->inventory[1]);
    }

    if (cmd == "pick 1") {
        playerInstance->pickUpItem(playerInstance->location->items[0]);
    }

    if (cmd == "drop 2") {
        playerInstance->dropItem(playerInstance->inventory[1]);
    }

    if (cmd == "go") {
        std::cout << "You can go to the... " << std::endl;
        playerInstance->showAvailableLocations();
    }

    if (cmd == "#{godmode}") {
        std::cout << "LOL." << std::endl;
    }

    if (cmd == "collect 2") {
        std::cout << "You tried to pick up the " + playerInstance->location->items[1]->name + ", but it was too heavy." << std::endl;
    }

    if (cmd == "go 1") {
        std::cout << "You went to the north." << std::endl;
        playerInstance->location = *&playerInstance->location->locations["north"];
        std::cout << "GAME: You are in the ";
        std::cout << playerInstance->location->name << std::endl;
        std::cout << playerInstance->location->description << std::endl;
    }

    if (cmd == "stats") {
        std::cout << "Statistics:" << std::endl;
        std::cout << "\nPLAYER: " << std::endl;
        std::cout << "health: ";
        std::cout << playerInstance->health << std::endl;
        std::cout << "level: ";
        std::cout << playerInstance->level << std::endl;
        std::cout << "exp: ";
        std::cout << playerInstance->experiencePoints << std::endl;
        std::cout << "gold: ";
        std::cout << playerInstance->gold << std::endl;
        std::cout << "location: ";
        std::cout << playerInstance->location->name << std::endl;
        std::cout << "\nATTACK: " << std::endl;
        playerInstance->actualWeapon();
        std::cout << "rating: ";
        std::cout << playerInstance->attack << std::endl;
        std::cout << "\nDEFENSE: " << std::endl;
        playerInstance->actualArmor();
        std::cout << "rating: ";
        std::cout << playerInstance->armor << std::endl;
    }

    if (cmd == "inv") {
        std::cout << "Inventory:" << std::endl;
        playerInstance->show(playerInstance->inventory);
    }

    if (cmd == "armor") {
        playerInstance->actualArmor();
    }

    if (cmd == "weapon") {
        playerInstance->actualWeapon();
    }

    if (cmd == "loc") {
        std::cout << "GAME: You are in the ";
        std::cout << playerInstance->location->name << std::endl;
    }

    if (cmd == "locDesc") {
        std::cout << playerInstance->location->description << std::endl;
    }

    if (cmd == "ls") {
        std::cout << "On the ground lies:" << std::endl;
        playerInstance->show(playerInstance->location->items);
    }
}
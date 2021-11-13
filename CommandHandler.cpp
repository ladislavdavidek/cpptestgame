//
// Created by Ladislav Davídek on 13.11.2021.
//

#include <iostream>
#include "Mob.h"
#include "CommandHandler.h"

void CommandHandler::handle(Mob playerInstance, std::string command) {
    Mob player = playerInstance;
    std::string cmd = command;
    /*
    if (cmd == "equipW") {
        player.equipItem();
    }

    if (cmd == "equipA") {
        player.equipItem();
    }
    */

    if (cmd == "inv") {
        std::cout << "Inventar:" << std::endl;
        player.show(player.inventory);
    }

    if (cmd == "aa") {
        std::cout << "Aktivni armor: ";
        std::cout << player.activeArmor.name << std::endl;
    }

    if (cmd == "aw") {
        std::cout << "Aktivni zbran: ";
        std::cout << player.activeWeapon.name << std::endl;
    }

    if (cmd == "loc") {
        std::cout << "Aktualni location: ";
        std::cout << player.location.name << std::endl;
    }

    if (cmd == "locDesc") {
        std::cout << player.location.description << std::endl;
    }

    if (cmd == "dmg") {
        std::cout << "Aktualni damage: ";
        std::cout << player.attack << std::endl;
    }

    if (cmd == "hp") {
        std::cout << "Aktualni hp: ";
        std::cout << player.health << std::endl;
    }

    if (cmd == "def") {
        std::cout << "Aktualni armor: ";
        std::cout << player.armor << std::endl;
    }

    if (cmd == "ls") {
        player.show(player.location.items);
    }
}
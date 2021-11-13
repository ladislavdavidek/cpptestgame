//
// Created by Ladislav Davídek on 05.11.2021.
//

#include "Game.h"
#include "Generate.h"
#include "Location.h"


void Game::init() {
    start();
    this->round++;

    Mob player;
    Generate generate;
    player = generate.player(player);
    player.name = getName();
    std::cout << "GAME: Welcome, " + player.name << std::endl;

    Location testLoc;
    testLoc.name = "Testovaci mistnost";
    testLoc.description = "Mistnost pro testovaci ucely.";

    player.location = testLoc;

    Item weapon = weapon.createItem('w', "Long sword", 0, 0, 20);
    Item weapon2 = weapon2.createItem('w', "Short sword", 0, 0, 15);
    Item weapon3 = weapon3.createItem('w', "Dagger", 0, 0, 10);
    Item weapon4 = weapon4.createItem('w', "Knife", 0, 0, 5);
    Item armor = armor.createItem('a', "Leather vest", 0, 1, 0);
    Item armor2 = armor2.createItem('a', "Chain vest", 0, 10, 0);

    player.equipItem(weapon);

    player.equipItem(armor);

    while (this->isRunning) {
        std::cout << "GAME: Whats your next step?" << std::endl;
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "equipW") {
            player.equipItem(weapon4);
        }

        if (cmd == "equipA") {
            player.equipItem(armor2);
        }

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
        
        if (cmd == "q") {
            stop();
        }
    }
    
}

void Game::start() {
    this->isRunning = true;
}

void Game::stop() {
    this->isRunning = false;
}

std::string Game::getName() {
    std::string name;
    std::cout << "GAME: Who are you?" << std::endl << "HERO: My name is ";
    //std::cin >> name;
    name = "Tester \n";
    return name;
}

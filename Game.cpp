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
    Location *loc = new Location();
    Item *item = new Item();
    Generate generate;
    player = generate.player(player);
    player.name = getName();
    std::cout << "GAME: Welcome, " + player.name << std::endl;

    
    for (int i = 0; i <= 4; i++) {
        item->name = "test_item";
        item->healthIncrease = 0;
        item->armorIncrease = 0;
        item->attackIncrease = 0;

        loc->items.push_back(*item);
    }
    
    loc->name = "Testovaci mistnost";
    loc->description = "Mistnost pro testovaci ucely.";

    player.location = loc;

    Item weapon = item->createItem("Pistole", 0, 0, 20);
    Item weapon2 = item->createItem("Rifle", 0, 0, 20);
    Item weapon3 = item->createItem("SMG", 0, 0, 15);
    Item weapon4 = item->createItem("Knife", 0, 0, 5);
    Item armor = armor.createItem("Vest", 0, 10, 0);

    player.equipItem('w', &weapon);

    while (this->isRunning) {
        std::cout << "GAME: Whats your next step?" << std::endl;
        std::string cmd;
        std::cin >> cmd;

        std::cout << "priakz: " + cmd << std::endl;

        if (cmd == "equip") {
            player.equipItem('w', &weapon4);
        }

        if (cmd == "inv") {
            std::cout << "Inventar:" << std::endl;
            player.show(player.inventory);
        }

        if (cmd == "aw") {
            std::cout << "Aktivni zbran: ";
            std::cout << player.activeWeapon->name << std::endl;
        }

        if (cmd == "loc") {
            std::cout << "Aktualni location: ";
            std::cout << player.location->name << std::endl;
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
            player.show(player.location->items);
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

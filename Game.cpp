//
// Created by Ladislav Davídek on 05.11.2021.
//

#include "Game.h"

void Game::init() {
    start();
    this->round++;
    
    Mob player;
    Generate generate;
    player = generate.player(player);
    player.name = player.getName();
    std::cout << "GAME: Welcome, " + player.name << std::endl;

    Item weapon = weapon.createItem('w', "Long sword", 0, 0, 20);
    Item weapon2 = weapon2.createItem('w', "Short sword", 0, 0, 15);
    Item weapon3 = weapon3.createItem('w', "Dagger", 0, 0, 10);
    Item weapon4 = weapon4.createItem('w', "Knife", 0, 0, 5);
    Item armor = armor.createItem('a', "Leather vest", 0, 1, 0);
    Item armor2 = armor2.createItem('a', "Chain vest", 0, 10, 0);

    Location testLoc;
    testLoc.name = "Testovaci mistnost";
    testLoc.description = "Mistnost pro testovaci ucely.";
    testLoc.items.push_back(weapon2);
    testLoc.items.push_back(weapon3);
    player.location = testLoc;

    player.equipItem(weapon);
    player.equipItem(armor);

    while (this->isRunning) {
        std::cout << "GAME: Whats your next step?" << std::endl;
        std::string cmd;
        std::cin >> cmd;
        this->cmdHandler.handle(player, cmd);

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


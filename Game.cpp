//
// Created by Ladislav Davídek on 05.11.2021.
//

#include "Game.h"
#include "Generate.h"
#include "Loop.h"

Loop gameloop;
Generate generate;
Mob player;

void Game::init() {
    gameloop.start();

    player = generate.player(player);
    player.name = getName();
    std::cout << "GAME: Welcome, " + player.name << std::endl;
    std::cout << player.name << std::endl;
    std::cout << player.attack << std::endl;
    std::cout << player.armor << std::endl;
    std::cout << player.gold << std::endl;
}

std::string Game::getName() {
    std::string name;
    std::cout << "GAME: Who are you?" << std::endl << "HERO: My name is ";
    std::cin >> name;
    return name;
}

//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include "Generate.h"
#include "Mob.h"

Mob Generate::enemy() {}

Mob Generate::player(Mob mob) {
    Mob player;
    Item item;

    player.health = 100;
    player.armor = 0;
    player.attack = 0;

    player.gold = 50;
    player.experiencePoints = 0;
    player.level = 1;

    player.inventory = std::initializer_list<Item>();
    player.activeWeapon = item;
    player.activeArmor = item;

    return player;
}
//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include "Generate.h"

Person Generate::enemy() {
    Person enemy;
    return enemy;
}

void Generate::player(Person* playerPtr) {
    playerPtr->health = 100;
    playerPtr->armor = 0;
    playerPtr->attack = 0;

    playerPtr->gold = 50;
    playerPtr->experiencePoints = 0;
    playerPtr->level = 1;
}
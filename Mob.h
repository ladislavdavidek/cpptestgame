//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#ifndef UNTITLED2_MOB_H
#define UNTITLED2_MOB_H

#include "Item.h"

class Mob {
public:
    std::string name;
    int health;
    int armor;
    int attack;
    int gold;
    int experiencePoints;
    int level;
    int round;
    std::initializer_list<Item> inventory;
    Item *activeWeapon;
    Item activeArmor;

private:

};


#endif //UNTITLED2_MOB_H

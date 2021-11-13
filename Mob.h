//
// Created by Ladislav Davídek on 05.11.2021.
//


#include <iostream>
#include <vector>
#include "Item.h"
#include "Location.h"

#ifndef UNTITLED2_MOB_H
#define UNTITLED2_MOB_H

class Mob {
public:
    std::string name;
    int health;
    int armor;
    int attack;
    int gold;
    int experiencePoints;
    int level;
    std::vector<Item> inventory;
    Item *activeWeapon = new Item();
    Item *activeArmor = new Item();
    Location *location = new Location();

    void show(std::vector<Item> list);
    void Mob::equipItem(char identifier, Item *item);
    std::atomic_bool hasEquiped(char identifier, Item *item);

    void lookForItems();

private:
    void storeAndEquip(std::atomic_bool store, Item *item);
};


#endif //UNTITLED2_MOB_H

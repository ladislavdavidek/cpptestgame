//
// Created by Ladislav Davídek on 05.11.2021.
//


#include <iostream>
#include <vector>
#include "Item.h"
#include "Location.h"

#ifndef UNTITLED2_MOB_H
#define UNTITLED2_MOB_H

class Person {
public:
    std::string name;
    int health;
    int armor;
    int attack;
    int gold;
    int experiencePoints;
    int level;
    std::vector<Item*> inventory;
    Item* activeWeapon;
    Item* activeArmor;
    Location* location;

    void show(std::vector<Item*> list);
    void actualArmor();
    void actualWeapon();

    void Person::equipItem(Item* item);
    std::atomic_bool hasEquiped(Item* item);

    void Person::pickUpItem(Item* item);
    void Person::dropItem(Item* item);

    std::string getName();
    void showAvailableLocations();

private:
    void storeAndEquip(std::atomic_bool store, Item* item);
    void store(Item* item);
    void equip(Item* item);
};


#endif //UNTITLED2_MOB_H

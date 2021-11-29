//
// Created by Ladislav Davídek on 05.11.2021.
//


#include <iostream>
#include <vector>
#include "Item.h"
#include "Location.h"
#include "Globals.h"

#ifndef UNTITLED2_PERSON_H
#define UNTITLED2_PERSON_H

class Person {
public:
    Person();
    std::string name;
    int health;
    int armor;
    int attack;
    int gold;
    int experiencePoints;
    int level;
    bool canBeAttacked;
    std::vector<Item*> inventory;
    std::vector<Item*> equippedItems;
    Item* activeWeapon;
    Item* activeArmor;
    Item* activeShield;
    Location* location;

    // METHODS -----

    void equipItem(Item* item);
    bool hasEquiped(Item* item);

    void pickUpItem(Item* item);
    void dropItem(Item* item);

    std::string getName();

    void actualArmor();
    void actualWeapon();
    void availableLocations();
    void attackableEntities();
    void lookAround();
    void showStats();
    void showInventory();
    void showItemsNearby();
    void itemsToDrop();
    void itemsToTake();
    void itemsToEquip();
    void itemsToUse();
    void itemsToUnequip();
    void thingsToExamine();

    void goTo(int listIndex);
    void fight(int listIndex);
    void use(int listIndex);
    void unequipItem(Item* item);

    void createPlayer(Person* self);

private:
    void setLocation(int listIndex);
    void loopItemsWithTitle(std::vector<Item*> list, std::string title);
    void loopLocationsWithTitle(std::vector<Location*> list, std::string title);
    void storeAndEquip(std::atomic_bool store, Item* item);
    void store(Item* item);
    void equip(Item* item);
    void unequip(Item* item);
};


#endif //UNTITLED2_PERSON_H

//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include "Person.h"

GlobalItems gitems;
GlobalLocations glocations;

Person::Person() {
    this->name = "";
    this->health = 100;
    this->armor = 0;
    this->attack = 0;

    this->gold = 0;
    this->experiencePoints = 0;
    this->level = 1;
    this->canBeAttacked;

    this->inventory.clear();
    this->activeWeapon;
    this->activeArmor;
    this->activeShield;
    this->location;
}

void Person::actualArmor() {
    if (this->activeWeapon->name.length() == 0) {
        std::cout << "No armor equipped." << std::endl;
    }
    else {
        std::cout << "You are wearing ";
        std::cout << this->activeArmor->name + "." << std::endl;
    }
    if (this->activeShield->name.length() == 0) {
        std::cout << "No shield equipped." << std::endl;
    }
    else {
        std::cout << "You are carrying ";
        std::cout << this->activeShield->name + "." << std::endl;
    }
}

void Person::actualWeapon() {
    if (!this->activeWeapon->name.length()) {
        std::cout << "No weapon equipped." << std::endl;
    }
    else {
        std::cout << "Your weapon is ";
        std::cout << this->activeWeapon->name + "." << std::endl;
    }
}

void Person::equipItem(Item* item) {
    if (item->id == 'w' || item->id == 'a' || item->id == 's') {
        hasEquiped(item) ? storeAndEquip(true, item) : storeAndEquip(false, item);
    }
    else {
        std::cout << "You cannot equip " + item->name + "." << std::endl;
    }
}

bool Person::hasEquiped(Item* item) {
    if (item->id == 'w' && this->activeWeapon->name.length() > 0) {
        return true; 
    }
    if (item->id == 'a' && this->activeArmor->name.length() > 0) {
        return true;
    }
    if (item->id == 's' && this->activeShield->name.length() > 0) {
        return true;
    }
    return false;
}

std::string Person::getName() {
    std::string name;
    std::cout << "Who are you?" << std::endl << "My name is Tester" << std::endl;
    //std::cin >> name;
    name = "Tester \n";
    return name;
}

void Person::availableLocations() { loopLocationsWithTitle(this->location->locations, "You can go to"); }

void Person::showStats() {
    std::cout << "Player:\n" << std::endl;
    std::cout << "Health     : ";
    std::cout << this->health << std::endl;
    std::cout << "Level      : ";
    std::cout << this->level << std::endl;
    std::cout << "Experience : ";
    std::cout << this->experiencePoints << std::endl;
    std::cout << "Gold       : ";
    std::cout << this->gold << std::endl;
    std::cout << "Location   : ";
    std::cout << this->location->name << std::endl;
    std::cout << std::endl;
    std::cout << "Weapon     : ";
    std::cout << this->activeWeapon->name << std::endl;
    std::cout << "Damage     : ";
    std::cout << this->attack << std::endl;
    std::cout << std::endl;
    std::cout << "Armor      : ";
    std::cout << this->activeArmor->name << std::endl;
    std::cout << "Shield     : ";
    std::cout << this->activeShield->name << std::endl;
    std::cout << "Defense    : ";
    std::cout << this->armor << std::endl;
}

// SINGLE WORD COMMANDS -----

void Person::showInventory() { loopItemsWithTitle(this->inventory, "Inventory"); }

void Person::showItemsNearby() { loopItemsWithTitle(this->location->items, "Items nearby"); }

void Person::itemsToDrop() { loopItemsWithTitle(this->inventory, "Drop item"); }

void Person::itemsToTake() { loopItemsWithTitle(this->location->items, "Take item"); }

void Person::itemsToEquip() { loopItemsWithTitle(this->inventory, "Equip item"); }

void Person::attackableEntities() { fight(0); }

void Person::itemsToUse() { loopItemsWithTitle(this->location->items, "Use item"); }

void Person::itemsToUnequip() { loopItemsWithTitle(this->equippedItems, "Unequip item"); }

void Person::thingsToExamine() { loopItemsWithTitle(this->location->items, "Examine item from"); }

// WORD WITH NUMBER COMMANDS -----

void Person::goTo(int listIndex) { setLocation(listIndex); }

void Person::fight(int listIndex) { std::cout << "Fight not implemented yet." << std::endl; }

void Person::use(int listIndex) { std::cout << "Item usage not implemented yet." << std::endl; }


void Person::createPlayer(Person* self) {
    self->health = 100;
    self->armor = 0;
    self->attack = 0;

    self->gold = 50;
    self->experiencePoints = 0;
    self->level = 1;

    self->inventory.clear();
    self->activeWeapon;
    self->activeArmor;
    self->activeShield;
    self->location;
}

void Person::lookAround() {
    std::cout << this->location->description + "\n" << std::endl;

    /*
    std::cout << "You see" << std::endl;
    std::cout << "1) Small heap of hay" << std::endl;
    this->location->description += "\nOn the ground, there is small heap of hay, which you have slept on.";
    std::cout << "2) Lever\n" << std::endl;
    this->location->description += "\nOn the wall, there is a lever.";
    //this->revealHiddenItems();
    */
}

void Person::setLocation(int listIndex) {
    this->location = this->location->locations[listIndex];
    std::cout << this->location->name << std::endl;
}

void Person::loopItemsWithTitle(std::vector<Item*> list, std::string title) {
    if (title.length() > 0) {
        std::cout << title + ":\n" << std::endl;
    }
    if (list.size() > 0) {
        for (int i = 0; i < list.size(); i++) {
            std::cout << i + 1;
            std::cout << ") " + list[i]->name << std::endl;
        }
    }
    else {
        std::cout << "No items." << std::endl;
    }
}

void Person::loopLocationsWithTitle(std::vector<Location*> list, std::string title) {
    if (title.length() > 0) {
        std::cout << title + ":\n" << std::endl;
    }
    if (list.size() > 0) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i]->name.length() > 0) {
                std::cout << i + 1;
                std::cout << ") " + list[i]->name << std::endl;
            }
        }
    }
    else {
        std::cout << "Aight, you cant go anywhere and you're fucked." << std::endl;
    }
}

void Person::storeAndEquip(std::atomic_bool storeBool, Item* item) {
    if (storeBool) {
        store(item);
        equip(item);
    } else {
        equip(item);
    }
    std::cout << item->name + " equipped." << std::endl;
}

void Person::store(Item* item) {
    if (item->id == 'w') {
        std::cout << this->activeWeapon->name + " stored." << std::endl;
        this->inventory.push_back(this->activeWeapon);
        this->attack -= this->activeWeapon->attackIncrease;
    }
    else if (item->id == 'a') {
        std::cout << this->activeArmor->name + " stored." << std::endl;
        this->inventory.push_back(this->activeArmor);
        this->armor -= this->activeArmor->armorIncrease;
    }
    else if (item->id == 's') {
        std::cout << this->activeShield->name + " stored." << std::endl;
        this->armor -= this->activeShield->armorIncrease;
        this->inventory.push_back(this->activeShield);
    }
}

void Person::equip(Item* item) {
    if (item->id == 'w') {
        this->activeWeapon = item;
        this->equippedItems.push_back(item);
        this->attack += item->attackIncrease;
    }
    else if (item->id == 'a') {
        this->activeArmor = item;
        this->equippedItems.push_back(item);
        this->armor += item->armorIncrease;
    }
    else if (item->id == 's') {
        this->activeShield = item;
        this->equippedItems.push_back(item);
        this->armor += item->armorIncrease;
    }
    this->inventory.erase(std::remove(this->inventory.begin(), this->inventory.end(), item), this->inventory.end());
}

void Person::unequipItem(Item* item) {
    if (item->id == 'w') {
        this->attack -= item->attackIncrease;
        this->activeWeapon = gitems.emptyItem();
    }
    else if (item->id == 'a') {
        this->armor -= item->armorIncrease;
        this->activeArmor = gitems.emptyItem();
    }
    else if (item->id == 's') {
        this->armor -= item->armorIncrease;
        this->activeShield = gitems.emptyItem();
    }
    this->inventory.push_back(item);
    this->equippedItems.erase(std::remove(this->equippedItems.begin(), this->equippedItems.end(), item), this->equippedItems.end());
}

void Person::pickUpItem(Item* item) {
    if (this->inventory.size() < 5) {
        this->inventory.push_back(item);
        this->location->items.erase(std::remove(this->location->items.begin(), this->location->items.end(), item), this->location->items.end());
        std::cout << "You picked up " + item->name + "." << std::endl;
    }
    else {
        std::cout << "You can't carry more items!" << std::endl;
    }
}

void Person::dropItem(Item* item) {
    this->location->items.push_back(item);
    this->inventory.erase(std::remove(this->inventory.begin(), this->inventory.end(), item), this->inventory.end());
    std::cout << "You dropped " + item->name + "." << std::endl;
}

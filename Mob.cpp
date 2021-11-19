//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include "Mob.h"
 
void Person::show(std::vector<Item*> list) {
    if (list.size() > 0) {
        for (int i = 0; i < list.size(); i++) {
            std::cout << i + 1;
            std::cout << ") " + list[i]->name << std::endl;
        }
    } else {
        std::cout << "No items." << std::endl;
    }
}

void Person::actualArmor() {
    if (this->activeWeapon->name.length() == 0) {
        std::cout << "No armor equipped." << std::endl;
    }
    else {
        std::cout << "You are wearing ";
        std::cout << this->activeArmor->name + "." << std::endl;
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
    hasEquiped(item) ? storeAndEquip(true, item) : storeAndEquip(false, item);
}

std::atomic_bool Person::hasEquiped(Item* item) {
    if (item->id == 'w') {
        if (this->activeWeapon->name.length() > 0) {
            return true; 
        }
        else {
            return false;
        }
    } else if (item->id == 'a') {
        if (this->activeArmor->name.length() > 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

std::string Person::getName() {
    std::string name;
    std::cout << "GAME: Who are you?" << std::endl << "HERO: My name is Tester" << std::endl;
    //std::cin >> name;
    name = "Tester \n";
    return name;
}

void Person::showAvailableLocations() {
    int i = 1;
    if (this->location->locations["north"]->name.length() > 0) {
        std::cout << i;
        std::cout << ") " + this->location->locations["north"]->name << std::endl;
        i++;
    }
    if (this->location->locations["east"]->name.length() > 0) {
        std::cout << i;
        std::cout << ") " + this->location->locations["east"]->name << std::endl;
        i++;
    }
    if (this->location->locations["south"]->name.length() > 0) {
        std::cout << i;
        std::cout << ") " + this->location->locations["south"]->name << std::endl;
        i++;
    }
    if (this->location->locations["west"]->name.length() > 0) {
        std::cout << i;
        std::cout << ") " + this->location->locations["west"]->name << std::endl;
        i++;
    }
}

void Person::storeAndEquip(std::atomic_bool storeBool, Item* item) {
    if (storeBool) {
        store(item);
        equip(item);
    } else {
        equip(item);
    }
    std::cout << "GAME: You equipped " + item->name << std::endl;
}

void Person::store(Item* item) {
    if (item->id == 'w') {
        std::cout << "GAME: You stored your " + this->activeWeapon->name + " into your pocket." << std::endl;
        this->inventory.push_back(this->activeWeapon);
    }
    else if (item->id == 'a') {
        std::cout << "GAME: You stored your " + this->activeArmor->name + " into your pocket." << std::endl;
        this->inventory.push_back(this->activeArmor);
    }
}
void Person::equip(Item* item) {
    if (item->id == 'w') {
        this->activeWeapon = item;
        this->attack += item->attackIncrease;
    }
    else if (item->id == 'a') {
        this->activeArmor = item;
        this->armor += item->armorIncrease;
    }
    this->inventory.erase(std::remove(this->inventory.begin(), this->inventory.end(), item), this->inventory.end());
}

void Person::pickUpItem(Item* item) {
    this->inventory.push_back(item);
    this->location->items.erase(std::remove(this->location->items.begin(), this->location->items.end(), item), this->location->items.end());
    std::cout << "GAME: You picked up " + item->name + "." << std::endl;
}

void Person::dropItem(Item* item) {
    this->location->items.push_back(item);
    this->inventory.erase(std::remove(this->inventory.begin(), this->inventory.end(), item), this->inventory.end());
    std::cout << "GAME: You dropped " + item->name + "." << std::endl;
}

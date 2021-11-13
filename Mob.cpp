//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include "Mob.h"
 
void Mob::show(std::vector<Item> list) {
    if (list.size() > 0) {
        for (int i = 0; i < list.size(); i++) {
            std::cout << i + 1;
            std::cout << ") " + list[i].name << std::endl;
        }
    } else {
        std::cout << "Empty." << std::endl;
    }
    
}

void Mob::equipItem(Item item) {
    hasEquiped(item) ? storeAndEquip(true, item) : storeAndEquip(false, item);
}

std::atomic_bool Mob::hasEquiped(Item item) {
    if (item.id == 'w') {
        if (this->activeWeapon.name.length() > 0) {
            return true; 
        }
        else {
            return false;
        }
    } else if (item.id == 'a') {
        if (this->activeArmor.name.length() > 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

std::string Mob::getName() {
    std::string name;
    std::cout << "GAME: Who are you?" << std::endl << "HERO: My name is ";
    //std::cin >> name;
    name = "Tester \n";
    return name;
}

void Mob::storeAndEquip(std::atomic_bool storeBool, Item item) {
    if (storeBool) {
        store(item);
        equip(item);
    } else {
        equip(item);
    }
}

void Mob::store(Item item) {
    if (item.id == 'w') {
        this->inventory.push_back(this->activeWeapon);
    }
    else if (item.id == 'a') {
        this->inventory.push_back(this->activeArmor);
    }
}
void Mob::equip(Item item) {
    if (item.id == 'w') {
        this->activeWeapon = item;
    }
    else if (item.id == 'a') {
        this->activeArmor = item;
    }
}





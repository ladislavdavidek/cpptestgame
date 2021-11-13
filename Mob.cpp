//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include <vector>
#include "Mob.h"
 
void Mob::show(std::vector<Item> list) {
    if (list.size() > 0) {
        for (int i = 0; i < list.size(); i++) {
            std::cout << i + 1;
            std::cout << ") " + list[i].name << std::endl;
        }
    } else {
        std::cout << "List is empty." << std::endl;
    }
    
}

void Mob::equipItem(char identifier, Item *item) {

    if (identifier == 'w') {
        (hasEquiped(identifier, item)) ? storeAndEquip(true, item) : storeAndEquip(false, item);
    }
    else if (identifier == 'a') {
        (hasEquiped(identifier, item)) ? storeAndEquip(true, item) : storeAndEquip(false, item);
    }
        
}

std::atomic_bool Mob::hasEquiped(char identifier, Item *item) {
    if (identifier == 'w') {
        if (this->activeWeapon->name.length() > 0) {
            return true; 
        }
        else {
            return false;
        }
    } else if (identifier == 'a') {
        if (this->activeArmor) {
            return true;
        }
        else {
            return false;
        }
    }
}

void Mob::storeAndEquip(std::atomic_bool store, Item *item) {
    if (store) {
        std::cout << "davam do inv" << std::endl;
        this->inventory.push_back(*this->activeWeapon);
        std::cout << "nasazuji novy" << std::endl;
        this->activeWeapon = item;
    } else {
        std::cout << "nasazuji novy" << std::endl;
        this->activeWeapon = item;
    }
}





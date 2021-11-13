//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include "Item.h"

Item::Item() {
    std::cout << "Constructor called." << std::endl;
}

Item Item::createItem(std::string name, int healthIncrease, int armorIncrease, int attackIncrease) {
    Item item;
    item.name = name;
    item.healthIncrease = healthIncrease;
    item.armorIncrease = armorIncrease;
    item.attackIncrease = attackIncrease;
    item.description = "";
    return item;
}
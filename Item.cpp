//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include "Item.h"

Item Item::createItem(char id, std::string name, int healthIncrease, int armorIncrease, int attackIncrease) {
    Item item;
    item.id = id;
    item.name = name;
    item.healthIncrease = healthIncrease;
    item.armorIncrease = armorIncrease;
    item.attackIncrease = attackIncrease;
    item.description = "";
    return item;
}
//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#ifndef UNTITLED2_ITEM_H
#define UNTITLED2_ITEM_H

class Item {
public:
    Item();
    std::string name;
    int healthIncrease;
    int armorIncrease;
    int attackIncrease;
    std::string description;

    Item createItem(std::string name, int healthIncrease, int armorIncrease, int attackIncrease);
};


#endif //UNTITLED2_ITEM_H

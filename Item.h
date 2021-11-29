//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#ifndef UNTITLED2_ITEM_H
#define UNTITLED2_ITEM_H

class Item {
public:
    char id;
    bool canBeStored;
    bool isEquipped;

    std::string name;
    std::string description;

    int healthIncrease;
    int armorIncrease;
    int attackIncrease;

    Item newEmptyItem();
    Item newModifiedItem(char id, bool canBeStored, bool isEquipped, std::string name, std::string description, int healthIncrease, int armorIncrease, int attackIncrease);
    void modifyItem(Item* self, char id, bool canBeStored, bool isEquipped, std::string name, std::string description, int healthIncrease, int armorIncrease, int attackIncrease);
};

#endif //UNTITLED2_ITEM_H

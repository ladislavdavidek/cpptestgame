//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include "Item.h"

/*
items:
    ids:
        e: empty
        a: armor
        s: shield
        w: weapon
        x: static (canBeStored = false)
        k: key
        c: common item
        h: heal
*/

Item Item::newEmptyItem() {
    Item item;
    modifyItem(&item, 'e', true, false, "", "", 0, 0, 0);
    return item;
}

Item Item::newModifiedItem(char id, bool canBeStored, bool isEquipped, std::string name, std::string description, int healthIncrease, int armorIncrease, int attackIncrease) {
    Item item;
    modifyItem(&item, id, canBeStored, isEquipped, name, description, healthIncrease, armorIncrease, attackIncrease);
    return item;
}

void Item::modifyItem(Item* self, char id, bool canBeStored, bool isEquipped, std::string name, std::string description, int healthIncrease, int armorIncrease, int attackIncrease) {
    self->id = id;
    self->canBeStored = canBeStored;
    self->isEquipped = isEquipped;
    self->name = name;
    self->description = description;
    self->healthIncrease = healthIncrease;
    self->armorIncrease = armorIncrease;
    self->attackIncrease = attackIncrease;
}

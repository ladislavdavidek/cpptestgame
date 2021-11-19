//
// Created by Ladislav Davídek on 07.11.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include "Item.h"

#ifndef UNTITLED2_LOCATION_H
#define UNTITLED2_LOCATION_H

class Location {
public:
    std::string name;
    std::string description;
    std::map<std::string, Location*> locations;
    std::vector<Item*> items;

    void createLocation(std::string name, std::string description, std::map<std::string, Location*> locations, std::vector<Item*> items);
};

#endif //UNTITLED2_LOCATION_H
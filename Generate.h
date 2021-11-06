//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#ifndef UNTITLED2_GENERATE_H
#define UNTITLED2_GENERATE_H


#include "Mob.h"

class Generate {
public:
    static Mob enemy();
    static Mob player(Mob mob);
};


#endif //UNTITLED2_GENERATE_H

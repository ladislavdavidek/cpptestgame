//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#ifndef UNTITLED2_GAME_H
#define UNTITLED2_GAME_H

#include "Mob.h"

class Game {
public:
    static void init();

private:
    int round;
    std::atomic_bool isRunning;
    static std::string getName();
};

#endif //UNTITLED2_GAME_H

//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include "Mob.h"

#ifndef UNTITLED2_GAME_H
#define UNTITLED2_GAME_H

class Game {
public:
    int round;
    std::atomic_bool isRunning;
    void init();

private:
    void start();
    void stop();
    static std::string getName();
};

#endif //UNTITLED2_GAME_H

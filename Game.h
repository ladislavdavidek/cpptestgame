//
// Created by Ladislav Davídek on 05.11.2021.
//

#include <iostream>
#include <string>
#include "Person.h"
#include "Item.h"
#include "Generate.h"
#include "Location.h"
#include "CommandHandler.h"

#ifndef UNTITLED2_GAME_H
#define UNTITLED2_GAME_H

class Game {
public:
    int round;
    bool isRunning;
    CommandHandler cmdHandler;
    void init();
    void start();
    void stop();
    void save();
};

#endif //UNTITLED2_GAME_H

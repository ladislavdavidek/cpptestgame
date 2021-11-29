#include <iostream>

#include "Game.h"
#include "CommandHandler.h"
//#include "ProjectSettings.h"

int main() {
    Game game;
    CommandHandler handler;
    //ProjectSettings project;

    //if (!project.debug()) {}

    bool isRunning = true;

    std::cout << "MEDIEVAL GAME" << std::endl;
    std::cout << std::endl;
    std::cout << "Main menu:" << std::endl;
    std::cout << std::endl;
    std::cout << "1) PLAY" << std::endl;
    std::cout << "2) CONTROLLS" << std::endl;
    std::cout << "3) ABOUT" << std::endl;
    std::cout << "4) QUIT" << std::endl;
    std::cout << std::endl;

    while (isRunning) {
        std::cout << ">> ";
        std::string cmd;
        std::getline(std::cin, cmd);
        std::cout << std::endl;

        if (cmd == "1") { game.init(); break; }
        if (cmd == "2") { std::cout << "controlls" << std::endl;}
        if (cmd == "3") { std::cout << "about" << std::endl;}
        if (cmd == "4") { isRunning = false; break; }

        std::cout << std::endl;
    }   
}

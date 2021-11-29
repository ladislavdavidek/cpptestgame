//
// Created by Ladislav Davídek on 13.11.2021.
//

#include "CommandHandler.h"

/*
    single word commands:

    inv: i,
    look: l,
    stats: p,
    armor: a,
    weapon: w,
    quit: q,
    save: v,

    go: g,
    take: t,
    drop: d,
    equip: e,
    fight: f,

    use: u,
    unequip: n,
    examine: x,



    word and num commands:

    go: g,
    take: t,
    drop: d,
    equip: e,
    fight: f,



    word and word commands:

    use: u,
    unequip: n,
    examine: x,
*/

void CommandHandler::handle(Person* playerInstance, std::string command) {
    std::string cmd = command;
    std::string functionCaller = cmd.substr(0, cmd.find(" "));
    std::string functionArgument;
    int cmdIndex;

    std::regex singleWordComm("([A-z]+)");
    std::regex wordAndNumComm("([A-z]+)[ ]([0-9]+)");
    std::regex wordAndWordComm("([$][A-z]+)[ ]([A-z]+)");

    if (doesCommandMatchRegex(cmd, singleWordComm)) {
        singleWordCommands(playerInstance, functionCaller);
    }
    else if (doesCommandMatchRegex(cmd, wordAndNumComm)) {
        cmdIndex = std::stoi(cmd.substr(cmd.find(" ") + 1, -1)) - 1;
        wordAndNumCommands(playerInstance, functionCaller, cmdIndex);
        }
    else if (doesCommandMatchRegex(cmd, wordAndWordComm)) {
        functionArgument = cmd.substr(cmd.find(" ")+1, -1);
        wordAndWordCommands(playerInstance, functionCaller, functionArgument);
    }
    else {
        std::cout << "Unknown command" << std::endl;
    }
}

bool CommandHandler::doesCommandMatchRegex(std::string cmd, std::regex regx) {
    if (std::regex_match(cmd, regx)) { return true; }
    return false;
}

void CommandHandler::singleWordCommands(Person* playerInstance, std::string cmd) {
    if (cmd == "i") { playerInstance->showInventory(); }

    else if (cmd == "l") { playerInstance->lookAround(); }

    else if (cmd == "p") { playerInstance->showStats(); }

    else if (cmd == "a") { playerInstance->actualArmor(); }

    else if (cmd == "w") { playerInstance->actualWeapon(); }

    else if (cmd == "g") { playerInstance->availableLocations(); }

    else if (cmd == "t") { playerInstance->itemsToTake(); }

    else if (cmd == "d") { playerInstance->itemsToDrop(); }

    else if (cmd == "e") { playerInstance->itemsToEquip(); }

    else if (cmd == "f") { playerInstance->attackableEntities(); }

    else if (cmd == "u") { playerInstance->itemsToUse(); }

    else if (cmd == "n") { playerInstance->itemsToUnequip(); }

    // toto ukazovat podle nastaveni obtiznosti
    else if (cmd == "x") { playerInstance->thingsToExamine(); }

    else { std::cout << "Unknown command" << std::endl; }
}

void CommandHandler::wordAndNumCommands(Person* playerInstance, std::string cmd, int cmdIndex) {
    if (cmd == "g") { playerInstance->goTo(cmdIndex); }

    else if (cmd == "t") { playerInstance->pickUpItem(playerInstance->location->items[cmdIndex]); }

    else if (cmd == "d") { playerInstance->dropItem(playerInstance->inventory[cmdIndex]); }

    else if (cmd == "e") { playerInstance->equipItem(playerInstance->inventory[cmdIndex]); }

    else if (cmd == "f") { playerInstance->fight(cmdIndex); }

    else if (cmd == "u") { playerInstance->use(cmdIndex); }
    
    else if (cmd == "n") { playerInstance->unequipItem(playerInstance->equippedItems[cmdIndex]); }

    else if (cmd == "x") {}

    else { std::cout << "Unknown command" << std::endl; }
}

void CommandHandler::wordAndWordCommands(Person* playerInstance, std::string cmd, std::string functionArgument) {
    // cheats here :D just for developers:D
    std::cout << "Cheat command" << std::endl;
        
}

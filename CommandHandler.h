//
// Created by Ladislav Davídek on 13.11.2021.
//

#include <iostream>
#include <ostream>
#include <regex>
#include "Person.h"
#include "Location.h"

#ifndef UNTITLED2_COMMANDHANDLER_H
#define UNTITLED2_COMMANDHANDLER_H

class CommandHandler {
public:
	void handle(Person* playerInstance, std::string command);

private:
	bool doesCommandMatchRegex(std::string cmd, std::regex regx);

	void singleWordCommands(Person* playerInstance, std::string cmd);
	void wordAndNumCommands(Person* playerInstance, std::string functionCaller, int index);
	void wordAndWordCommands(Person* playerInstance, std::string functionCaller, std::string functionArgument);
};

#endif //UNTITLED2_COMMANDHANDLER_H

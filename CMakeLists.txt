cmake_minimum_required(VERSION 3.20)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 main.cpp Game.h Game.cpp Person.cpp Person.h Generate.cpp Generate.h Loop.cpp Loop.h Item.cpp Item.h "CommandHandler.h" "CommandHandler.cpp" "Globals.h" "Globals.cpp")

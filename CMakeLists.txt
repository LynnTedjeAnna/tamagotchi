cmake_minimum_required(VERSION 3.28)
project(tamagotchi)

set(CMAKE_CXX_STANDARD 26)

include_directories(src)
include_directories(include)
include_directories(diagrams)

add_executable(tamagotchi main.cpp
        src/pet.cpp
        src/object.cpp
        src/display.cpp
        src/game.cpp
        src/keyboard.cpp
        src/buttons.cpp)
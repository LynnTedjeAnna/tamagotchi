//
// Created by Lynn Meindertsma on 23/04/2024.
//
#ifndef PET_CPP_GAME_HPP
#define PET_CPP_GAME_HPP

#include "pet.hpp"
#include "input.hpp"

class Game{
public:
    Game(Input* input);
    Pet pet;
    Input* input;

    void start();
    void update();              // Update the game state
    void render();              // Render the game screen
    void manage_time();         // Manages time for the pet, simulating real-time passage

private:
};
#endif //PET_CPP_GAME_HPP
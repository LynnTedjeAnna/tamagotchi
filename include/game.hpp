//
// Created by Lynn Meindertsma on 23/04/2024.
//
#ifndef PET_CPP_GAME_HPP
#define PET_CPP_GAME_HPP

#include "pet.hpp"
#include "input.hpp"

typedef enum {
    INPUT_NONE = 0,
    SELECT = 1,
    EXECUTE = 2,
    CANCEL = 3
} menu_choice;

typedef enum{
    FEED = 1,
    PLAY = 2,
    TRAIN = 3
}menu_options;


class Game{
public:
    Game(Input* input);
    Pet pet;
    Input* input;

    void start();
    uint8_t get_user_input();   // Get user input
    void menu();                // menu functionality
    void update();              // Update the game state
    void render();              // Render the game screen
    void manage_time();         // Manages time for the pet, simulating real-time passage

private:
    uint32_t menu_input;
};
#endif //PET_CPP_GAME_HPP

#include "game.hpp"


Game::Game(Input* input) { this->input = input;}

void Game::start() {
    // Initialize game resources and state
    // TODO: (example) load game state (after/if save game state is made)
}

// 1. make separate method in Game for user input that returns an enum type (NONE, SELECT, EXECUTE, CANCEL)
//todo: same for pc and arduino?
//only for select,execute and cancel input possible (menu choices)
uint8_t Game::get_user_input() {
    menu_input = 0;
    do {scanf("%d", &menu_input);}
    while (menu_input > CANCEL);
    return menu_input;
}
// TODO: menu functionality (new method in Game)
void Game::menu() {
    //test print statement
    printf("feed \n\r play \n\r train \n\r");
    get_user_input();
    if (menu_input == CANCEL){ return;}
    if (menu_input == SELECT){

    }
    if (menu_input == EXECUTE){

    }
}
void Game::update() {
    // todo: update pet's state, check level up, check evolution, manage time, etc.
    // TODO: edit these values based on user interaction
    pet_train_t train = TRAIN_NONE;
    pet_food_t food = FOOD_NONE;
    bool play = false;

    // 1. user interaction
    input->update();
    if (input->get_select()) {
        // todo: functionality
        printf("select pressed\n\r");
        play = true;  // TEST
    }
    if (input->get_execute()) {
        // todo: functionality
        printf("execute pressed\n\r");
        food = BERRY;  // TEST
    }
    if (input->get_cancel()) {
        // todo: functionality
        printf("cancel pressed\n\r");
        train = WALK;  // TEST
    }

    // 2. act on user interaction
    //todo: run based on user interaction
    if (food) { pet.feed(food); }
    if (play) { pet.play(); }
    if (train) { pet.train(train);}

    // 3. check states:
    if(pet.level_up()) {
        //todo: render screen with level up
        printf("Your pet grew a level! \n\r");
    }
    if(pet.evolution()) {
        //todo: render screen with evolution animation
        printf("Your pet is evolving! \n\r");
    }
    if (pet.friendship_level()) {
        //todo: render screen with friendship level up
        printf("Your pet grew a level in friendship! \n\r");
    }

    // 4. render
    render();
}

void Game::render() {
    // Render entire game state to the screen
    //print screen
}
 //todo: Implement time management function
void Game::manage_time() {
    // Simulate passage of time and update game state accordingly
}

#include <iostream>
#include "game.hpp"
#include "keyboard.hpp"


Keyboard keyboard('a', 'b', 'c', 'd');
Game game(&keyboard);

int main() {
    game.start();
    // save game
    // game run function that stops game after save with button functionality
    return 0;  // exit
}


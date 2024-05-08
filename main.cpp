#include <iostream>
#include "game.hpp"
#include "keyboard.hpp"


Keyboard keyboard('a', 'b', 'c');
Game game(&keyboard);

int main() {
    game.start();

    // A Game CANNOT be made WITHOUT an infinite loop!!!
    while (true) {
        game.update();
    }

    // save game
    // game run function that stops game after save with button fuctonality
    return 0;  // exit
}

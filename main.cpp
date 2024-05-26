#include <iostream>
#include "game.hpp"
#include "keyboard.hpp"

#ifdef PC

Keyboard keyboard('a', 'b', 'c', 'd');
Game game(&keyboard);

int main() {
    game.start();
    // save game
    // game run function that stops game after save with button functionality
    return 0;  // exit
}

#else

#include <Arduino.h>
void setup() {
  Serial.begin(9600);
}

void loop() {
}

#endif
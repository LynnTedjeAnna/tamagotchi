//
// Created by Lynn Meindertsma on 08/05/2024.
//
#include "buttons.hpp"

#ifndef PC
#include <Arduino.h>

Buttons::Buttons(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    select = a;
    execute = b;
    cancel = c;
}
void Buttons::button_setup() {
    pinMode(select, INPUT_PULLUP);
    pinMode(execute, INPUT_PULLUP);
    pinMode(cancel, INPUT_PULLUP);
}
void Buttons::update()     {}
bool Buttons::get_select() { return digitalRead(select) == HIGH;}
bool Buttons::get_execute() { return digitalRead(execute) == HIGH;}
bool Buttons::get_cancel() { return digitalRead(cancel) == HIGH;}

#else
Buttons::Buttons(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    (void)a; (void)b; (void)c; (void)d;
}
void Buttons::update() {}
bool Buttons::get_select() { return 0; }
bool Buttons::get_execute() { return 0; }
bool Buttons::get_cancel() { return 0; }
bool Buttons::get_save() { return 0;}

#endif
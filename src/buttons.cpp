//
// Created by Lynn Meindertsma on 08/05/2024.
//
#include "buttons.hpp"


#ifndef PC
//#include <Arduino.h>


Buttons::Buttons(uint8_t a, uint8_t b, uint8_t c) {
    select = a;
    execute = b;
    cancel = c;
}

void Buttons::update()     {}

bool Buttons::get_select() {
    return digitalRead(select) == HIGH;
}

bool Buttons::get_execute() {

}

bool Buttons::get_cancel() {

}
#else
Buttons::Buttons(uint8_t a, uint8_t b, uint8_t c) {
    (void)a; (void)b; (void)c;
}

void Buttons::update()        {}
bool Buttons::get_select()    { return 0; }
bool Buttons::get_execute()   { return 0; }
bool Buttons::get_cancel()    { return 0; }


#endif
//
// Created by Lynn Meindertsma on 07/05/2024.
//
#ifndef PET_CPP_KEYBOARD_HPP
#define PET_CPP_KEYBOARD_HPP

#include "input.hpp"

class Keyboard : public Input {
public:
    Keyboard(char s, char e, char c, char x);
    // Override functions from the base class
    void update() override;
    bool get_select() override;
    bool get_execute() override;
    bool get_cancel() override;
    bool get_save() override;
private:
    char select;
    char execute;
    char cancel;
    char save;
    char ch;
};

#endif // PET_CPP_KEYBOARD_HPP

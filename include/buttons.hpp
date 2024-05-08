//
// Created by Lynn Meindertsma on 08/05/2024.
//
#ifndef PET_CPP_BUTTONS_HPP
#define PET_CPP_BUTTONS_HPP

#include "input.hpp"

class Buttons : public Input {
public:
    //button pins from controller rich shield arduino
    Buttons(uint8_t a, uint8_t b, uint8_t c);
    // Override functions from the base class
    void update() override;
    bool get_select() override;
    bool get_execute() override;
    bool get_cancel() override;
private:
    uint8_t select;
    uint8_t execute;
    uint8_t cancel;
};


#endif //PET_CPP_BUTTONS_HPP

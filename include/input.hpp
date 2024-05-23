//
// Created by Lynn Meindertsma on 07/05/2024.
//
#ifndef PET_CPP_INPUT_HPP
#define PET_CPP_INPUT_HPP

#include <cstdint>
#include <cstdio>

class Input {
public:
    // Pure virtual functions for handling input
    virtual void update() = 0;
    virtual bool get_select() = 0;
    virtual bool get_execute() = 0;
    virtual bool get_cancel() = 0;
    virtual bool get_save() = 0;
};

#endif // PET_CPP_INPUT_HPP

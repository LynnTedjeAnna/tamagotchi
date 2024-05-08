//
// Created by Lynn Tedje Anna Meindertsma on 22 Apr 2024.
//
#ifndef PET_CPP_ENTITY_HPP
#define PET_CPP_ENTITY_HPP

#include <cstdio>
#include <cstdint>

class Entity{
public:
    virtual void update() = 0; // Pure virtual function
    virtual void draw() = 0;   // Pure virtual function

protected:
    //public for the inherited classes
    uint8_t position_x;
    uint8_t position_y;
};
#endif //PET_CPP_ENTITY_HPP

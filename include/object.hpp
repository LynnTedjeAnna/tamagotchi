//
// Created by Lynn Tedje Anna Meindertsma on 22 Apr 2024.
//
#ifndef PET_CPP_OBJECT_HPP
#define PET_CPP_OBJECT_HPP
#include "entity.hpp"

class Object : public Entity {
public:
    void update() override;
    void draw() override;

    void use();
private:

};
#endif //PET_CPP_OBJECT_HPP

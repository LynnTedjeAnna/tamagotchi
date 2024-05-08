//
// Created by Lynn Tedje Anna Meindertsma on 22 Apr 2024.
//
#ifndef PET_CPP_PET_HPP
#define PET_CPP_PET_HPP

#include "entity.hpp"
#include <cmath>


typedef enum {
    FOOD_NONE = 0,
    BERRY = 1,
    APPLE = 2
} pet_food_t;

typedef enum {
    TRAIN_NONE = 0,
    WALK = 1,
    RUN = 2
} pet_train_t;


class Pet : public Entity {
public:
    void update() override;
    void draw() override;
    void feed(pet_food_t food);
    void play();
    void train(pet_train_t train);
    bool level_up();
    bool evolution();
    bool friendship();
    void health();
    void move();

private:
    uint16_t hunger;                    //-> feed
    const uint16_t max_hunger = 200;
    uint32_t exp;                       //-> level_up
    uint8_t level;
    uint32_t level_cap;
    const uint8_t xp_base = 100;
    const float scale = 1.1;
    const uint8_t evolution_one = 20;
    const uint8_t evolution_two = 45;
    uint8_t evolution_stage;
    uint32_t happiness;                 //-> friendship
    uint32_t happiness_cap;
    uint8_t friendschip_level = 0;
    uint16_t hp = 15;             //-> health
};

#endif //PET_CPP_PET_HPP

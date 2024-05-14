#include "pet.hpp"
// TODO: CHECK SCALLING OF EVERY FUNCTION   (level(cap), hp, xp, friendship, hp decrease (health))
// Draw method implementation
void Pet::draw() {
    // Implement draw logic to draw pet on screen (terminal)
}
// Update method implementation
void Pet::update() {
    // Implement update logic to update status of the pet (scene)
}

void Pet::feed(pet_food_t food) {
    // Decrease pet's hunger and increase happiness based on the type of food (represented by an integer)
    switch (food) {
        case BERRY: // Food type 1
            hunger -= (10 + hunger_bonus);
            happiness += 5;
            //todo: make functional
            printf("You fed your pet with a berry! \n\r");
            if (hunger < 0) { hunger = 0; }                     // Ensure that hunger and happiness values stay within valid range
            break;
        case APPLE: // Food type 2
            hunger -= (20 + hunger_bonus);
            happiness += 10;
            //todo: make functional
            printf("You fed your pet with an apple! \n\r");
            if (hunger < 0) { hunger = 0; }                     // Ensure that hunger and happiness values stay within valid range
            break;
        //todo: Add more cases for other food types
        default:
            // Handle invalid food types
            printf("Error, invalid input \n\r");
            break;
    }
}

//todo: after playing ... min increase happiness, increase hunger immediately
void Pet::play() {
    // Increase pet's happiness and hunger (gain exp?)
    hunger += 0;
    happiness += 0;

    // Ensure that hunger and happiness values stay within valid range
    if (hunger < 0) { hunger = 0; }
    if (hunger > max_hunger){ hunger = max_hunger; }
}

void Pet::train(pet_train_t train) {
    switch (train) {
        case WALK: // training type 1
            hunger += (10 - hunger_bonus);
            exp += (5 + exp_bonus);
            //todo: make functional
            printf("You trained your pet with walking! \n\r");
            if (hunger > max_hunger){ hunger = max_hunger; }        // Ensure that hunger and happiness values stay within valid range
            break;
        case RUN: // training type 2
            hunger += (20 - hunger_bonus);
            exp += (10 + exp_bonus);
            //todo: make functional
            printf("You trained your pet with running! \n\r");
            if (hunger > max_hunger){ hunger = max_hunger; }        // Ensure that hunger and happiness values stay within valid range
            break;
        //todo: Add more cases for other food types
        default:
            //todo: exceptions
            // Handle invalid food types
            printf("Error, invalid input \n\r");
            break;
    }
}
bool Pet::level_up() {
    level_cap = pow((level * xp_base), scale);
    if (exp >= level_cap){
        //level up when exp is high enough
        level++;
        hp = pow(level, 1.2);
        return true;
    }
    return false;
}
bool Pet::evolution(){
    // todo: check logic, is there better way?
    // todo: current and next evolution and render evolution animation
    if (level == evolution_one){
        evolution_stage = 1;
        return true;
    }else if (level == evolution_two){
        evolution_stage = 2;
        return true;
    }
    return false;
}
bool Pet::friendship_level() {
    // Implement friendship logic to interact with the pet and increase friendship level
    happiness_cap = pow((level * xp_base), scale);
    if (happiness >= happiness_cap){
        //level up when exp is high enough
        friendship++;
        friendship_perks();     //todo: friendship_perks location?
        return true;
    }
    return false;
}
void Pet::friendship_perks() {
    if (friendship <= 20){
        exp_bonus = pow(friendship, 1.1);           // Increase xp gain (until lvl 20)
    }
    else if (friendship <= 40 ){
        hunger_bonus = pow(friendship, 0.9);        // Lower hunger decrease speed (from lvl 20, until 40)
    }
    else if (friendship <= 60){                             //todo: increase defence (from lvl 40, until 60?)

    }
}

//todo: what other hp funcionalities, for example time passed alone -hp
void Pet::health() {
    // Implement health logic to check and update the health status of the pet
    printf("%d Hunger before \n\r", hunger);
    if  (hunger > 95){  hp-= pow((level + 45), 1.2);
    }else if (hunger > 80){  hp-= pow((level + 20), 1.2);
    } else if (hunger > 60){ hp-= pow((level + 10), 1.2);}
    printf("Your pets health has decreased :( new hunger is: ");
    printf("%d\n\r", hunger);
}

void Pet::move() {
    // Implement move logic to move the pet
}

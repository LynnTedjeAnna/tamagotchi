#include "pet.hpp"

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
    // Determine the effects based on the type of food
    switch (food) {
        case BERRY: // Food type 1
            hunger -= 10;
            happiness += 5;
            //todo: make functional
            printf("You fed your pet with type 1! \n\r");
            break;
        case APPLE: // Food type 2
            hunger -= 20;
            happiness += 10;
            //todo: make functional
            printf("You fed your pet with type 2! \n\r");
            break;
        //todo: Add more cases for other food types
        default:
            // Handle invalid food types
            printf("Error, invalid input \n\r");
            break;
    }
    // Ensure that hunger values stay within valid range
    if (hunger < 0) { hunger = 0; }
    if (hunger > max_hunger){ hunger = max_hunger; }
}
void Pet::play() {
    // Increase pet's happiness and hunger (gain exp?)
    hunger += 0;
    happiness += 0;
    //todo: after playing ... min increase happiness, increase hunger immediately

    // Ensure that hunger and happiness values stay within valid range
    if (hunger < 0) { hunger = 0; }
    if (hunger > max_hunger){ hunger = max_hunger; }
}
void Pet::train(pet_train_t train) {
    // Gained exp to increase pet's level through training
    //todo: enum trainings (names)
    switch (train) {
        case WALK: // training type 1
            hunger += 10;
            exp += 5;
            //todo: make functional
            printf("You trained your pet with type 1! \n\r");
            break;
        case RUN: // training type 2
            hunger += 20;
            exp += 10;
            //todo: make functional
            printf("You trained your pet with type 2! \n\r");
            break;
        //todo: Add more cases for other food types
        default:
            // Handle invalid food types
            printf("Error, invalid input \n\r");
            break;
    }
}
bool Pet::level_up() {
    // Level up logic to increase the level of the pet
    level_cap = pow((level * xp_base), scale);
    if (exp >= level_cap){
        //level up when exp is high enough
        level++;
        //todo: increase hp with level
        hp = pow(level, 1.2);
        return true;
    }
    return false;
}
bool Pet::evolution(){
    // Implement evolution logic when increase the level of the pet
    //todo: check logic, is there better way?
    // TODO: current and next evolution and render evolution animation
    if (level == evolution_one){
        evolution_stage = 1;
        return true;
    }else if (level == evolution_two){
        evolution_stage = 2;
        return true;
    }
    return false;
}
// todo: purpose for friendship level
bool Pet::friendship() {
    // Implement friendship logic to interact with the pet and increase friendship level
    happiness_cap = pow((level * xp_base), scale);
    if (happiness >= happiness_cap){
        //level up when exp is high enough
        friendschip_level++;
        return true;
    }
    // 1. increase xp gain              (until lvl 20)
    // 2. lower hunger decrease speed   (from lvl 20)
    // 3. increase defence              (from lvl 40)
    return false;
}
// Health method implementation
void Pet::health() {
    // Implement health logic to check and update the health status of the pet
    printf("%d Hunger before \n\r", hunger);
    if  (hunger > 95){  hp-= pow((level + 45), 1.2);
    }else if (hunger > 80){  hp-= pow((level + 20), 1.2);
    } else if (hunger > 60){ hp-= pow((level + 10), 1.2);}
    printf("Your pets health has decreased :( new hunger is: ");
    printf("%d\n\r", hunger);
    //todo: what other hp funcionalities, for example time passed alone -hp
}
// Move method implementation
void Pet::move() {
    // Implement move logic to move the pet
}

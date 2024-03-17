#include "RPG.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
RPG::RPG(){
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry";
}

/**
 * @brief Construct a new RPG::RPG object
 * 
 * @param name 
 * @param health 
 * @param strength 
 * @param defense 
 * @param type 
 */
RPG::RPG(string name, int health, int strength, int defense, string type){
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    
    setSkills();
}

// Accessor function
string RPG::getName() const{
    return name;
}

int RPG::getHealth() const{
    return health;
}

int RPG::getStrength() const{
    return strength;
}

int RPG::getDefense() const{
    return defense;
}

/**
 * @brief return whether health is greater than 0
 * 
 * @return true 
 * @return false 
 */
bool RPG::isAlive() const{
    return health > 0;
}

// Mutator function

/**
 * @brief update health into new health
 * 
 * @param new_health 
 */
void RPG::updateHealth(int new_health){
    health = new_health;
}

/**
 * @brief Give class and assign skills
 * 
 */
void RPG::setSkills(){
    if (type == "mage"){
        skills[0] = "fire";
        skills[1] = "thunder";
    } else if (type == "theif"){
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if (type == "archer"){
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

/**
 * @brief sets the skills based on the RPG's role
 * 
 * @param skill 
 * @param opponent 
 */
void RPG::printAction(string skill, RPG opponent){
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

/**
 * @brief attack decreases the opponent's health by (strength - opponent's defense)
 * In other words, the opponent's defense should soften the blow from the attack
 * 
 * For example, if opponent's health is 100, opponent's defense is 5, and player's
 * strength is 20, then after the attack, opponent's health should be
 * 85 (i.e. 100 - (20-5))
 * 
 * First calculate the opponent's health, then use (*opponent).getUpdate(new_health)
 * to update their health
 * 
 * @param opponent 
 */
void RPG::attack(RPG * opponent){
    
    // Opponent's health and defense stats stats
    int opp_health = (*opponent).getHealth();
    int opp_defense = (*opponent).getDefense();

    // Player strength stat
    int player_str = getStrength();

    // Opponent new health
    int new_health = opp_health - max((player_str - opp_defense), 0);

    // Updating Opponent health
    (*opponent).updateHealth(new_health);
}

/**
 * @brief prompts the user to choose skill and calls printAction() and attack()
 * 
 */
void RPG::useSkill(RPG *opponent){
    // use a for loop to print out all the player's skill
    // the code within your should print be:
    // printf("Skill %i: %s\n", i, skills[i].c_str());
    // where i is the index given your for loop
    // Recall the SKILL_SIZE is set to 2 within RPG.h
    // The values of i should be 0 <= i < SKILL_SIZE.
    
    // print player's skills
    for(int i = 0; i < SKILL_SIZE; i++){
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    // create an int called chosen_skill_index
    int chosen_skill_index;

    // use a print to output "Choose a skill to use: Enter 0 or 1\n" on the terminal
    printf("Choose a skill to use: Enter 0 or 1\n");

    // get user input and assign it to chosen_skill_index
    // (e.g. cin >> )
    cin >> chosen_skill_index;

    // assigns the chosen_skill_index into a string called chosen_skill
    // no modification needed here
    string chosen_skill = skills[chosen_skill_index];

    // call printAction(string, RPG) and use chosen_skill and (*opponent)
    // as parameters
    printAction(chosen_skill, (*opponent));

    //call attack on opponent
    attack(opponent);
}
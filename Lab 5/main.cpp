#include <iostream>
#include "RPG.h"
using namespace std;

int main(){
    //intialize object
    RPG firstPlayer = RPG();
    
    RPG secondPlayer = RPG("Jimmy", 100, 20, 5, "theif");

    // Inital health
    printf("First Player HP: %i | is alive: %i\n", firstPlayer.getHealth(), firstPlayer.isAlive());
    printf("Second Player HP: %i | is alive: %i\n", secondPlayer.getHealth(), secondPlayer.isAlive());

    // Update health
    firstPlayer.updateHealth(0);
    secondPlayer.updateHealth(0);

    // Death
    printf("First Player HP: %i | is alive: %i\n", firstPlayer.getHealth(), firstPlayer.isAlive());
    printf("Second Player HP: %i | is alive: %i\n", secondPlayer.getHealth(), secondPlayer.isAlive());
}
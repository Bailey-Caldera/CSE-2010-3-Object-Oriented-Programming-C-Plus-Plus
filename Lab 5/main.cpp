#include <iostream>
#include "RPG.h"
using namespace std;

/**
 * @brief Prints both player's name and their health.
 * Example output for name Wiz and NPC
 * Wiz health: 75 NPC health: 100\n
 * 
 * @param player1 
 * @param player2 
 */
void displayStats(RPG player1, RPG player2){
    
    //player 1 info
    string player1_name = player1.getName();
    int player1_health = player1.getHealth();

    //player 2 info
    string player2_name = player2.getName();
    int player2_health = player2.getHealth();

    //print both player name and current health
    printf("%s health: %i | %s health: %i\n", player1_name.c_str(), player1_health, player2_name.c_str(), player2_health);
}

/**
 * @brief Display who wins based on who is alive. Use an if statement to check whether
 * player 1 is alive. If so, print that they won, else player 2 won.
 * 
 * Example Output:
 * Wiz defeated NPC! Good game!\n
 * 
 * @param player1 
 * @param player2 
 */
void displayEnd(RPG player1, RPG player2){

    //player 1 name
    string player1_name = player1.getName();

    //player 2 name
    string player2_name = player2.getName();

    // Check if player 1 is alive
    if (player1.getHealth() <= 0){
        printf("%s defeated %s! Good game!\n", player1_name.c_str(), player2_name.c_str());
    }
    else {
        printf("%s defeated %s! Good game!\n", player2_name.c_str(), player1_name.c_str());
    }
}

/**
 * @brief uses a while loop to check whether both players are alive.
 * If so, it calls displayStats((*player1), (*player2))
 * Inside the while loop it:
 *  Then prints the name of player one to say that it is their turn
 *  Then call (*player1).useSkill(player2)
 *  Then prints "-------------------------------------\n"
 *  
 *  Repeat the process for player 2 acting on player 1 inside the same while loop
 *  Then prints the name of player two to say that it their turn
 *  Then call (*player2).useskill(player1)
 *  Then prints "-------------------------------------\n"
 * 
 Refer to the Role Playing Game Part Two instruction for the
 example output
 * 
 * @param player1 
 * @param player2 
 */
void gameLoop(RPG *player1, RPG *player2){
    
    //player 1 info
    string player1_name = (*player1).getName();

    //player 2 info
    string player2_name = (*player2).getName();

    while ((*player1).getHealth() > 0 && (*player2).getHealth() > 0){
        
        //display stats of both player
        displayStats((*player1), (*player2));

        //print player 1 turn
        printf("%s turn\n", player1_name.c_str());

        //player 1 use a skill to attack
        (*player1).useSkill(player2);

        //create visible spacing
        printf("----------------------------------------------\n");

        //display stats of both player
        displayStats((*player1), (*player2));

        //print player 2 turn
        printf("%s turn\n", player2_name.c_str());

        //player 2 use a skill to attack
        (*player2).useSkill(player1);

        //create visible spacing
        printf("----------------------------------------------\n");
    }
}

int main(){
    //intialize object
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    
    return 0;
}
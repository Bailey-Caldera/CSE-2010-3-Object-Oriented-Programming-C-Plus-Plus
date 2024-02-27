#ifndef RPG_H
#define RPG_H
#include <string>
using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:
        //constructor
        RPG();
        RPG(string name, int health, int strength, int defense, string type);
        
        // Class and show action
        void setSkills();
        void printAction(string action, RPG);

        // Mutator function
        void updateHealth(int new_health);
        //void attack(RPG *);
        //void useSkill(RPG *);

        // Accessor function
        bool isAlive() const;
        string getName() const; 
        int getHealth() const;
        int getStrength() const;
        int getDefense() const;

    private:
        string name;
        int health;
        int strength;
        int defense;
        string type;
        string skills[SKILL_SIZE];
};

#endif
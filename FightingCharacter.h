#ifndef FIGHTINGCHARACTER_H_INCLUDED
#define FIGHTINGCHARACTER_H_INCLUDED

#include <iostream>
#include <string>

#include "GameCharacter.h"

using namespace std;

class FightingCharacter : public GameCharacter
{
private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;

public:
    FightingCharacter();
    FightingCharacter(string name, string tag, int health, int attack, int defense);
    bool checkIsDead();
    /* return currentHealth */
    int increaseStatus(int health, int attack, int defense, bool addToMaxHealth);
    int takeDamage(int damage);

    /* Set & Get function*/
    void setMaxHealth(int health);
    void setCurrentHealth(int health);
    void setAttack(int attack);
    void setDefense(int defense);
    int getMaxHealth();
    int getCurrentHealth();
    int getAttack();
    int getDefense();
};

#endif
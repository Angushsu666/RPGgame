#include "FightingCharacter.h"

FightingCharacter::FightingCharacter():GameCharacter(){

}

FightingCharacter::FightingCharacter(string name, string tag, int health, int attack,int defense):GameCharacter(name, tag){
    this->maxHealth = health;
    this->currentHealth = health;
    this->attack = attack;
    this->defense = defense;
}

bool FightingCharacter::checkIsDead(){
    return this->currentHealth <= 0;
}

int FightingCharacter::takeDamage(int damage){
    int healthLost = 0;
    if(damage > this->defense){
        healthLost = damage-this->defense;
    }
    if(healthLost <= this->currentHealth){
        this->currentHealth = this->currentHealth-healthLost;
    }else{
        this->currentHealth = 0;
    }
    return this->currentHealth;
}

int FightingCharacter::increaseStatus(int health, int attack, int defense, bool addToMaxHealth){
    if(addToMaxHealth){
        this->maxHealth = this->maxHealth+health;
    }
    this->currentHealth = this->currentHealth+health;
    if(this->currentHealth < 0){
        this->currentHealth = 0;
    }
    this->attack = this->attack + attack;
    if(this->attack < 0){
        this->attack = 0;
    }
    this->defense = this->defense + defense;
    if(this->defense < 0){
        this->defense = 0;
    }
    return this->currentHealth;
}

/* Set & Get function*/
void FightingCharacter::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
}
void FightingCharacter::setCurrentHealth(int currentHealth){
    this->currentHealth = currentHealth;
}
void FightingCharacter::setAttack(int attack){
    this->attack = attack;
}
void FightingCharacter::setDefense(int defense){
    this-> defense = defense;
}
int FightingCharacter::getCurrentHealth(){
    return this->currentHealth;
}
int FightingCharacter::getAttack(){
    return this->attack;
}
int FightingCharacter::getDefense(){
    return this->defense;
}
int FightingCharacter::getMaxHealth(){
    return this->maxHealth;
}
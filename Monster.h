#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

using namespace std;

class Monster: public FightingCharacter
{
private:
    bool isBoss;
    string script;
public:
    Monster();
    Monster(string name,string script, int health,int attack,int defense, bool isBoss);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object* obj);
    void showStatus();
    void setIsBoss(bool isBoss);
    void setScript(string script);
    bool getIsBoss();
    string getScript();
};


#endif

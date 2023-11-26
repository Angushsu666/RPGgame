#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED

#include <iostream>
#include <string>

#include "Monster.h"

using namespace std;

class Potion : public Item
{
    public:
    Potion();
    Potion(string name, bool visible, bool isUsed, int health, int attack, int defense, int price);
    bool triggerEvent(Object* obj);
};

#endif 
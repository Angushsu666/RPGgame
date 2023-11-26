#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <iostream>
#include <string>

#include "Item.h"
#include "Player.h"

using namespace std;
class Player;
class Equipment : public Item
{
    private:
    string whereToPlace;
    
    public:
    Equipment();
    Equipment(string name, string whereToPlace, bool visible, int health, int attack, int defense, int price);
    string getWheretoPlace();
    void setWhereToPlace(string whereToPlace);
    bool triggerEvent(Object* obj);
};

#endif // EQUIPMENT_H_INCLUDED
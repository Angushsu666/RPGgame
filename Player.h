#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "Item.h"
#include "FightingCharacter.h"
#include "Room.h"
#include "Key.h"
#include "Potion.h"
#include "Equipment.h"

using namespace std;
class Equipment;
class Player: public FightingCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item*> backpack;
    Equipment* leftHand;
    Equipment* rightHand;
    Equipment* body;
    Equipment* head;
    int money;
public:
    Player();
    Player(string name,int health,int attack,int defense);
    void addItem(Item* item, bool toBakcpack);
    void increaseStates(int health,int attack,int defense);
    bool changeRoom(Room* room);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object* obj);

    /* Set & Get function*/
    void setCurrentRoom(Room* currentRoom);
    void setPreviousRoom(Room* previousRoom);
    void setBackpack(vector<Item*> backpack);
    void setLeftHand(Equipment* leftHand);
    void setRightHand(Equipment* rightHand);
    void setHead(Equipment* head);
    void setBody(Equipment* body);
    void setMoney(int money);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    Equipment* getLeftHand();
    Equipment* getRightHand();
    Equipment* getHead();
    Equipment* getBody();
    int getMoney();
    vector<Item*> getBackpack();
    void listBackpackItemAndUse();
    void removeEquipment();
    void removeItemInBackpack(int index);
};

#endif // PLAYER_H_INCLUDED

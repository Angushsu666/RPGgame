#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "Object.h"

using namespace std;

class Item: public Object
{
private:
    int health, attack, defense, price;
    bool visible;
public:
    Item();
    Item(string name, string tag, bool visible, int health, int attack, int defense, int price);

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    int getPrice();
    bool getVisible();
    void setHealth(int health);
    void setAttack(int attack);
    void setDefense(int defense);
    void setVisible(bool visible);
    void setPrice(int price);
    void printDetail();
};

#endif // ITEM_H_INCLUDED

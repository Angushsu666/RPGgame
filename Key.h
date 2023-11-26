#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED

#include <iostream>
#include <string>

#include "Item.h"
#include "Player.h"

using namespace std;

class Key : public Item
{
    private:
    string content;

    public:
    Key();
    Key(string name, string content, bool visible, int price);
    string getContent();
    void setContent(string content);
    bool triggerEvent(Object* obj);
};
#endif
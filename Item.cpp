#include "Item.h"

Item::Item() : Object()
{
}

Item::Item(string name, string tag, bool visible, int health, int attack, int defense, int price) : Object(name, tag)
{
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->visible = visible;
    this->price = price;
}

int Item::getHealth()
{
    return this->health;
}

int Item::getAttack()
{
    return this->attack;
}

int Item::getDefense()
{
    return this->defense;
}

int Item::getPrice()
{
    return this->price;
}

bool Item::getVisible()
{
    return this->visible;
}

void Item::setHealth(int health)
{
    this->health = health;
}

void Item::setAttack(int attack)
{
    this->attack = attack;
}

void Item::setDefense(int defense)
{
    this->defense = defense;
}

void Item::setVisible(bool visible)
{
    this->visible = visible;
}
void Item::setPrice(int price)
{
    this->price = price;
}
void Item::printDetail()
{
    cout << this->getName() << ": Price = " << this->getPrice();
    if (this->getTag() != "Key")
    {
        cout << ", Health = " << this->getHealth() << ", Attack = " << this->getAttack() << ", Defense = " << this->getDefense();
    }
}
#include "Potion.h"

Potion::Potion() : Item()
{
}

Potion::Potion(string name, bool visible, bool isUsed, int health, int attack, int defense, int price) : Item(name, "Potion", visible, health, attack, defense, price)
{
    //this->isUsed = isUsed;
}

/*bool Potion::getIsUsed()
{
    return this->isUsed;
}
void Potion::setIsUsed(bool isUsed)
{
    this->isUsed = isUsed;
}*/
bool Potion::triggerEvent(Object *obj)
{
    if (obj->getTag() == "Player")
    {
        Player *player = dynamic_cast<Player *>(obj);
        bool selectValid = false;
        while (!selectValid)
        {
            cout << endl
                 << "Do you want to put it in your backpack or use/equip it now?" << endl;
            cout << "1. Use / equip it." << endl;
            cout << "2. Put it in backpack." << endl;
            int puttingChoice;
            cin >> puttingChoice;
            if (puttingChoice == 1)
            {
                selectValid = true;
                player->addItem(this, false);
                cout << endl
                     << this->getName() << " is equipped / used." << endl;
            }
            else if (puttingChoice == 2)
            {
                selectValid = true;
                player->addItem(this, true);
                cout << endl
                     << this->getName() << " is collected into backpack." << endl;
            }
            else
            {
                cout << "Invalid choice! Choose again." << endl;
            }
        }
    }
    else if (obj->getTag() == "Monster")
    {
        Monster *monster = dynamic_cast<Monster *>(obj);
        cout << "Use " << this->getName() << " on " << monster->getName() << endl; 
        monster->increaseStatus(-this->getHealth(), -this->getAttack(), -this->getDefense(), false);
        monster->showStatus();
    }

    return true;
}
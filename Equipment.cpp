#include "Equipment.h"

Equipment::Equipment() : Item()
{
}

Equipment::Equipment(string name, string whereToPlace, bool visible, int health, int attack, int defense, int price) : Item(name, "Equipment", visible, health, attack, defense, price)
{
    this->whereToPlace = whereToPlace;
}

string Equipment::getWheretoPlace()
{
    return this->whereToPlace;
}
void Equipment::setWhereToPlace(string whereToPlace)
{
    this->whereToPlace = whereToPlace;
}
bool Equipment::triggerEvent(Object *obj)
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
    return true;
}
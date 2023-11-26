#include "Monster.h"

Monster::Monster() : FightingCharacter()
{
}
Monster::Monster(string name, string script, int health, int attack, int defense, bool isBoss) : FightingCharacter(name, "Monster", health, attack, defense)
{
    this->isBoss = isBoss;
    this->script = script;
}

/* Virtual function that you need to complete   */
/* In Monster, this function should deal with   */
/* the combat system.                           */
bool Monster::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player *>(obj);
    bool selectValid = false;
    bool attackEnd = false;
    string action;
    while (!selectValid || !attackEnd)
    {
        bool havePotion = false;
        for (int i = 0; i < player->getBackpack().size(); i++)
        {
            if (player->getBackpack()[i]->getTag() == "Potion")
            {
                havePotion = true;
            }
        }
        cout << endl
             << "Do you want to fight " << this->getName() << "?" << endl;
        cout << "A. Attack" << endl;
        cout << "R. Retreat" << endl;
        if (havePotion)
        {
            cout << "P. Use potion to attack" << endl;
        }
        cout << "> ";
        cin >> action;

        if (action == "A" || action == "a")
        {
            selectValid = true;
            cout << endl;
            cout << "You attack " << this->getName() << ". " << this->getName() << "'s health " << this->getCurrentHealth() << "->";
            this->takeDamage(player->getAttack());
            cout << this->getCurrentHealth() << "" << endl;
            if (this->getCurrentHealth() <= 0)
            {
                cout << this->getName() << " was defeated." << endl;
                cout << script << endl;
                for (int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++)
                {
                    string tag = player->getCurrentRoom()->getObjects()[i]->getTag();
                    if (tag == "Equipment" || tag == "Potion" || tag == "Key")
                    {
                        Item *item = dynamic_cast<Item *>(player->getCurrentRoom()->getObjects()[i]);
                        item->setVisible(true);
                    }
                }
                return true;
            }

            cout << this->getName() << " attack you. Your health " << player->getCurrentHealth() << "->";
            player->takeDamage(this->getAttack());
            cout << player->getCurrentHealth() << "" << endl;
            cout << endl;
            if (player->getCurrentHealth() <= 0)
            {
                cout << "You were defeated." << endl;
                return false;
            }
        }
        else if (action == "R" || action == "r")
        {
            selectValid = true;
            player->changeRoom(player->getPreviousRoom());
            return false;
        }
        else if (havePotion && (action == "P" || action == "p"))
        {
            selectValid = true;
            bool potionValid = false;
            while (!potionValid)
            {
                vector<int> potionIndex;
                for (int i = 0; i < player->getBackpack().size(); i++)
                {
                    if (player->getBackpack()[i]->getTag() == "Potion")
                    {
                        potionIndex.push_back(i);
                    }
                }
                cout << endl
                     << "Which potion do you want to use?" << endl;
                int option = 1;
                int potionTotal = potionIndex.size();
                for (int i = 0; i < potionTotal; i++)
                {
                    cout << option << ". ";
                    player->getBackpack()[potionIndex[i]]->printDetail();
                    cout << endl;
                    option++;
                }
                if (potionTotal == 0)
                {
                    cout << "You don't have any potion!" << endl;
                }
                cout << option << ". Cancel" << endl;

                int potionSelect;
                cout << "> ";
                cin >> potionSelect;
                if (potionSelect > 0 && potionSelect < option)
                {
                    int potionInBackpackIndex = potionIndex[potionSelect - 1];
                    cout << endl;
                    player->getBackpack()[potionInBackpackIndex]->triggerEvent(this);
                    cout << potionInBackpackIndex;
                    player->removeItemInBackpack(potionInBackpackIndex);
                    potionTotal--;
                    potionIndex.erase(potionIndex.begin() + potionSelect - 1);
                }
                else if (potionSelect == option)
                {
                    potionValid = true;
                }
                else
                {
                    cout << "Invalid choice! Choose again" << endl;
                }
            }
        }
        else
        {
            cout << "Invalid choice! Please choose again." << endl
                 << endl;
        }
    }
    return false;
}
void Monster::setIsBoss(bool isBoss)
{
    this->isBoss = isBoss;
}
bool Monster::getIsBoss()
{
    return this->isBoss;
}

void Monster::showStatus()
{
    cout << endl;
    cout << this->getName() << ": Health: " << this->getCurrentHealth() << "/" << this->getMaxHealth();
    cout << ", Attack: " << this->getAttack();
    cout << ", Defense: " << this->getDefense() << endl;
}
#include "Event.h"

Event::Event() : Object()
{
}
Event::Event(string name, string askScript, string endScript, string rightChoice, bool isKeyRequired, int addHealth, int addAttack, int addDefense) : Object(name, "Event")
{
    this->askScript = askScript;
    this->endScript = endScript;
    this->rightChoice = rightChoice;
    this->isKeyRequired = isKeyRequired;
    this->addHealth = addHealth;
    this->addAttack = addAttack;
    this->addDefense = addDefense;
}
void Event::setAskScript(string askScript)
{
    this->askScript = askScript;
}
void Event::setRightChoice(string rightChoice)
{
    this->rightChoice = rightChoice;
}
void Event::setEndScript(string endScript)
{
    this->endScript = endScript;
}
void Event::setIsKeyRequired(bool isKeyRequired)
{
    this->isKeyRequired = isKeyRequired;
}
string Event::getAskScript()
{
    return this->askScript;
}
string Event::getRightChoice()
{
    return this->rightChoice;
}
string Event::getEndScripe()
{
    return this->endScript;
}
bool Event::getIsKeyRequired()
{
    return this->isKeyRequired;
}
bool Event::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player *>(obj);
    cout << askScript;
    if (isKeyRequired)
    {
        // locked chest
        bool selectValid = false;
        while (!selectValid)
        {
            vector<string> keyContents;
            int option = 1;
            // list all player's key
            cout << endl << "Which key do you want to use?" << endl;
            for (int i = 0; i < player->getBackpack().size(); i++)
            {
                string tag = player->getBackpack()[i]->getTag();
                if (tag == "Key")
                {
                    Key *key = dynamic_cast<Key *>(player->getBackpack()[i]);
                    keyContents.push_back(key->getContent());
                    cout << option << ". " << key->getName() << endl;
                    option++;
                }
            }
            if (keyContents.size() == 0)
            {
                cout << "You don't have any key." << endl;
            }
            cout << option << ". Cancel" << endl;

            int playerSelect;
            cout << "> ";
            cin >> playerSelect;
            if (playerSelect == option)
            {
                // cancel
                selectValid = true;
                return false;
            }
            if (playerSelect > 0 && playerSelect < option)
            {
                // check if key match
                if (this->getRightChoice() == keyContents[playerSelect - 1])
                {
                    cout << endScript << endl;
                    player->setMaxHealth(player->getMaxHealth() + addHealth);
                    player->increaseStates(addHealth, addAttack, addDefense);
                    for (Object *obj : player->getCurrentRoom()->getObjects())
                    {
                        string tag = obj->getTag();
                        if (tag == "Equipment" || tag == "Key" || tag == "Potion")
                        {
                            Item *item = dynamic_cast<Item *>(obj);
                            item->setVisible(true);
                        }
                    }
                    return true;
                }
                selectValid = false;
                cout << "Wrong key!" << endl;
            }
            else
            {
                cout << "Invalid choice. Choose again." << endl;
            }
        }
    }
    else
    {
        // player reply
        cout << "> ";
        string reply;
        cin >> reply;
        string lowerRightChoice = this->getRightChoice();
        for (auto &s : lowerRightChoice)
        {
            lowerRightChoice = tolower(s);
        }
        if (this->rightChoice == reply || lowerRightChoice == reply)
        {
            player->setMaxHealth(player->getMaxHealth() + addHealth);
            player->increaseStates(addHealth, addAttack, addDefense);
            for (Object *obj : player->getCurrentRoom()->getObjects())
            {
                string tag = obj->getTag();
                if (tag == "Equipment" || tag == "Key" || tag == "Potion")
                {
                    Item *item = dynamic_cast<Item *>(obj);
                    item->setVisible(true);
                }
            }
            cout << endScript << endl;
            return true;
        }
    }

    return false;
}
int Event::getAddHealth()
{
    return this->addHealth;
}
int Event::getAddAttack()
{
    return this->addAttack;
}
int Event::getAddDefense()
{
    return this->addDefense;
}

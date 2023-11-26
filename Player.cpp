#include "Player.h"

Player::Player() : FightingCharacter()
{
}

Player::Player(string name, int health, int attack, int defense) : FightingCharacter(name, "Player", health, attack, defense)
{
    vector<Item *> backpack;
    this->backpack = backpack;
    this->leftHand = nullptr;
    this->rightHand = nullptr;
    this->head = nullptr;
    this->body = nullptr;
    this->currentRoom = nullptr;
    this->previousRoom = nullptr;
    this->money = 100;
}

// Done
void Player::addItem(Item *item, bool toBackpack)
{
    if (toBackpack)
    {
        // put into backpack
        this->backpack.push_back(item);
        return;
    }

    if (item->getTag() == "Equipment")
    {
        // equip
        Equipment *equipment = dynamic_cast<Equipment *>(item);
        if (equipment->getWheretoPlace() == "Head")
        {
            if (this->head != nullptr)
            {
                cout << endl
                     << this->head->getName() << " is replaced by new equipment: " << equipment->getName();
                this->setMaxHealth(this->getMaxHealth() - this->head->getHealth());
                this->increaseStates(-this->head->getHealth(), -this->head->getAttack(), -this->head->getDefense());
                this->addItem(this->head, true);
            }
            this->head = equipment;
        }
        else if (equipment->getWheretoPlace() == "Body")
        {
            if (this->body != nullptr)
            {
                cout << endl
                     << this->body->getName() << " is replaced by new equipment: " << equipment->getName();
                this->setMaxHealth(this->getMaxHealth() - this->body->getHealth());
                this->increaseStates(-this->body->getHealth(), -this->body->getAttack(), -this->body->getDefense());
                this->addItem(this->body, true);
            }
            this->body = equipment;
        }
        else if (equipment->getWheretoPlace() == "Left Hand")
        {
            if (this->leftHand != nullptr)
            {
                cout << endl
                     << this->leftHand->getName() << " is replaced by new equipment: " << equipment->getName();
                this->setMaxHealth(this->getMaxHealth() - this->leftHand->getHealth());
                this->increaseStates(-this->leftHand->getHealth(), -this->leftHand->getAttack(), -this->leftHand->getDefense());
                this->addItem(this->leftHand, true);
            }
            this->leftHand = equipment;
        }
        else if (equipment->getWheretoPlace() == "Right Hand")
        {
            if (this->rightHand != nullptr)
            {
                cout << endl
                     << this->rightHand->getName() << " is replaced by new equipment: " << equipment->getName();
                this->setMaxHealth(this->getMaxHealth() - this->rightHand->getHealth());
                this->increaseStates(-this->rightHand->getHealth(), -this->rightHand->getAttack(), -this->rightHand->getDefense());
                this->addItem(this->rightHand, true);
            }
            this->rightHand = equipment;
        }
        this->setMaxHealth(this->getMaxHealth() + equipment->getHealth());
        this->increaseStates(equipment->getHealth(), equipment->getAttack(), equipment->getDefense());
    }
    else if (item->getTag() == "Potion")
    {
        // use now
        Potion *potion = dynamic_cast<Potion *>(item);
        this->increaseStates(potion->getHealth(), potion->getAttack(), potion->getDefense());
        if (this->getCurrentHealth() > this->getMaxHealth())
        {
            this->setCurrentHealth(this->getMaxHealth());
        }
    }
    else if (item->getTag() == "Key")
    {
        Key *key = dynamic_cast<Key *>(item);
    }
}

// Done
void Player::increaseStates(int health, int attack, int defense)
{
    if (this->getCurrentHealth() + health >= this->getMaxHealth())
    {
        this->setCurrentHealth(this->getMaxHealth());
    }
    else
    {
        this->setCurrentHealth(this->getCurrentHealth() + health);
    }
    this->setAttack(this->getAttack() + attack);
    this->setDefense(this->getDefense() + defense);
}

// Done
bool Player::changeRoom(Room *room)
{
    if (!room->getIsLocked())
    {
        Room *tempRoom = this->currentRoom;
        this->previousRoom = tempRoom;
        this->currentRoom = room;
        return true;
    }
    bool haveKey = false;
    for (int i = 0; i < backpack.size(); i++)
    {
        if (backpack[i]->getTag() != "Key")
        {
            continue;
        }
        Key *key = dynamic_cast<Key *>(backpack[i]);
        string password = "For " + room->getName();
        if (key->getContent() == password)
        {
            cout << "Unlock " << room->getName() << " with " << key->getName() << endl;
            haveKey = true;
            room->setIsLocked(false);
            backpack.erase(backpack.begin() + i);
        }
    }
    if (haveKey)
    {
        Room *tempRoom = this->currentRoom;
        this->previousRoom = tempRoom;
        this->currentRoom = room;
        return true;
    }
    return false;
}

/* Virtual function that you need to complete   */
/* In Player, this function should show the     */
/* status of player.                            */
bool Player::triggerEvent(Object *obj)
{
    cout << endl;
    cout << "Player: " << this->getName() << endl;
    cout << "- Health: " << this->getCurrentHealth() << "/" << this->getMaxHealth() << endl;
    cout << "- Attack: " << this->getAttack() << endl;
    cout << "- Defense: " << this->getDefense() << endl;
    cout << "- Equipment: " << endl;
    if (this->getHead() != nullptr)
    {
        cout << "   Head: " << this->getHead()->getName() << " (Health: +" << this->getHead()->getHealth() << ", Attack: +" << this->getHead()->getAttack() << ", Defense: +" << this->getHead()->getDefense() << ")" << endl;
    }
    if (this->getBody() != nullptr)
    {
        cout << "   Body: " << this->getBody()->getName() << " (Health: +" << this->getBody()->getHealth() << ", Attack: +" << this->getBody()->getAttack() << ", Defense: +" << this->getBody()->getDefense() << ")" << endl;
    }
    if (this->getLeftHand() != nullptr)
    {
        cout << "   Left hand: " << this->getLeftHand()->getName() << " (Health: +" << this->getLeftHand()->getHealth() << ", Attack: +" << this->getLeftHand()->getAttack() << ", Defense: +" << this->getLeftHand()->getDefense() << ")" << endl;
    }
    if (this->getRightHand() != nullptr)
    {
        cout << "   Right hand: " << this->getRightHand()->getName() << " (Health: +" << this->getRightHand()->getHealth() << ", Attack: +" << this->getRightHand()->getAttack() << ", Defense: +" << this->getRightHand()->getDefense() << ")" << endl;
    }

    cout << "- Backpack: " << endl;
    for (Item *i : this->getBackpack())
    {
        cout << "   (" << i->getTag() << ") " << i->getName();
        if (i->getTag() != "Key")
        {
            cout << ": Health = " << i->getHealth() << ", Attack = " << i->getAttack() << ", Defense = " << i->getDefense();
        }
        cout << endl;
    }
    cout << "- Money: " << this->getMoney() << endl;
    cout << "- Current Room: " << this->getCurrentRoom()->getName() << endl;
    if (this->getPreviousRoom() != nullptr)
    {
        cout << "- Previous Room: " << this->getPreviousRoom()->getName() << endl;
    }
    cout << endl;
    return true;
}

void Player::listBackpackItemAndUse()
{
    if (this->getBackpack().size() == 0)
    {
        cout << "Your backpack is empty!" << endl;
        return;
    }

    int optionIndex = 1;
    bool selectValid = false;
    while (!selectValid)
    {
        cout << endl
             << "Which item do you want to use / equip?" << endl;
        vector<int> itemIndexes;
        for (int i = 0; i < this->getBackpack().size(); i++)
        {
            string tag = this->getBackpack()[i]->getTag();
            if (tag == "Equipment" || tag == "Potion")
            {
                cout << optionIndex << ". ";
                cout << "(" << this->getBackpack()[i]->getTag() << ") " << this->getBackpack()[i]->getName() << ": Health = " << this->getBackpack()[i]->getHealth() << ", Attack = " << this->getBackpack()[i]->getAttack() << ", Defense = " << this->getBackpack()[i]->getDefense() << endl;
                optionIndex++;
                itemIndexes.push_back(i);
            }
        }
        cout << optionIndex << ". Cancel" << endl;
        int playerSelect;
        cout << "> ";
        cin >> playerSelect;
        if (playerSelect > 0 && playerSelect < optionIndex)
        {
            selectValid = true;
            selectValid = true;
            addItem(this->getBackpack()[itemIndexes[playerSelect - 1]], false);
            cout << endl
                 << this->getBackpack()[itemIndexes[playerSelect - 1]]->getName() << " is equipped / used." << endl;
            removeItemInBackpack(itemIndexes[playerSelect - 1]);
        }
        else if (playerSelect == optionIndex)
        {
            selectValid = true;
        }
        else
        {
            selectValid = false;
        }
    }
}

/* Set & Get function*/
void Player::setCurrentRoom(Room *room)
{
    this->currentRoom = room;
}
void Player::setPreviousRoom(Room *room)
{
    this->previousRoom = room;
}
void Player::setBackpack(vector<Item *> backpack)
{
    this->backpack = backpack;
}
void Player::setLeftHand(Equipment *leftHand)
{
    this->leftHand = leftHand;
}
void Player::setRightHand(Equipment *rightHand)
{
    this->rightHand = rightHand;
}
void Player::setHead(Equipment *head)
{
    this->head = head;
}
void Player::setBody(Equipment *body)
{
    this->body = body;
}
void Player::setMoney(int money)
{
    this->money = money;
}
Room *Player::getCurrentRoom()
{
    return this->currentRoom;
}
Room *Player::getPreviousRoom()
{
    return this->previousRoom;
}
vector<Item *> Player::getBackpack()
{
    return this->backpack;
}
int Player::getMoney()
{
    return this->money;
}
Equipment *Player::getLeftHand()
{
    return this->leftHand;
}
Equipment *Player::getRightHand()
{
    return this->rightHand;
}
Equipment *Player::getHead()
{
    return this->head;
}
Equipment *Player::getBody()
{
    return this->body;
}
void Player::removeEquipment()
{
    bool selectValid = false;
    while (!selectValid)
    {
        cout << endl
             << "Which equipment do you want to remove?" << endl;
        bool haveH = head != nullptr;
        bool haveB = body != nullptr;
        bool haveL = leftHand != nullptr;
        bool haveR = rightHand != nullptr;
        if (haveH)
        {
            cout << "H. Remove head equipment" << endl;
        }
        if (haveB)
        {
            cout << "B. Remove body equipment" << endl;
        }
        if (haveL)
        {
            cout << "L. Remove left hand equipment" << endl;
        }
        if (haveR)
        {
            cout << "R. Remove right hand equipment" << endl;
        }
        if (!haveH && !haveB && !haveL && !haveR)
        {
            cout << "You don't have any equipment can be removed." << endl;
        }
        cout << "C. Cancel" << endl;

        string playerSelect;
        cin >> playerSelect;
        if (haveH && (playerSelect == "H" || playerSelect == "h"))
        {
            selectValid = true;
            backpack.push_back(head);
            head = nullptr;
        }
        else if (haveB && (playerSelect == "B" || playerSelect == "b"))
        {
            selectValid = true;
            backpack.push_back(body);
            body = nullptr;
        }
        else if (haveL && (playerSelect == "L" || playerSelect == "l"))
        {
            selectValid = true;
            backpack.push_back(leftHand);
            leftHand = nullptr;
        }
        else if (haveR && (playerSelect == "R" || playerSelect == "r"))
        {
            selectValid = true;
            backpack.push_back(rightHand);
            rightHand = nullptr;
        }
        else if (playerSelect == "C" || playerSelect == "c")
        {
            selectValid = true;
        }
        else
        {
            cout << "Invalid choice! Choose again" << endl;
        }
    }
}

void Player::removeItemInBackpack(int index)
{
    if (backpack.size() == 1)
    {
        backpack.pop_back();
    }
    else if (backpack.size() > 1)
    {
        backpack.erase(backpack.begin() + index);
    }
}

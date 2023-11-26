#include "Dungeon.h"

Dungeon::Dungeon()
{
    this->isBossAlive = true;
}
/* Create a new player, and give him/her basic status */
void Dungeon::createPlayer()
{
    cout << "What's your name?" << endl;
    string name;
    cout << "> ";
    cin >> name;
    this->player = Player(name, 10, 20, 10);
    this->player.setCurrentRoom(&this->rooms[0]);
}

/* Create a map, which include several different rooms */
void Dungeon::createMap()
{
    // create rooms
    vector<Object *> objectsForA;
    Potion *potionA = new Potion("Energy drink", true, false, 10, 10, 10, 0);
    Potion *potionA2 = new Potion("Energy drink2", true, false, 10, 10, 10, 0);
    objectsForA.push_back(potionA);
    objectsForA.push_back(potionA2);
    Room roomA = Room("Room A", false, false, 0, objectsForA);

    vector<Object *> objectsForB;
    string monsterScriptB = "Congradulations! You beat Cookie Monster. There is a sword in this room as your reward.";
    Monster *monsterInB = new Monster("Cookie Monster", monsterScriptB, 60, 20, 10, false);
    Equipment *equipInB = new Equipment("Sword", "Left Hand", false, 10, 20, 20, 0);
    objectsForB.push_back(monsterInB);
    objectsForB.push_back(equipInB);
    Room roomB = Room("Room B", false, false, 1, objectsForB);

    vector<Object *> objectsForC;
    string eventAskScriptC = "\nDo you want to train yourself to improve your health?\nY. Yes\nN. No\n";
    Event *eventC = new Event("Get some trainning in this room", eventAskScriptC, "Your body is stronger now!", "Y", false, 20, 20, 20);
    objectsForC.push_back(eventC);
    Room roomC = Room("Room C", false, false, 2, objectsForC);

    vector<Object *> objectsForD;
    vector<Item *> npcDCommodity;
    Key *npcDKey = new Key("Key for locked room", "For Room E", false, 0);
    Equipment *npcDEquip = new Equipment("Super Expensive Stuff", "Head", true, 10000, 10000, 10000, 10000);
    npcDCommodity.push_back(npcDKey);
    npcDCommodity.push_back(npcDEquip);
    string npcDScript = "Help! There are some monsters on the right side of this room! Please take the key from me and save people in this dungeon!";
    NPC *npcInD = new NPC("Guard", npcDScript, npcDCommodity);
    objectsForD.push_back(npcInD);
    Room roomD = Room("Room D", false, false, 3, objectsForD);

    vector<Object *> objectsForE;
    Equipment *equipE = new Equipment("Armor", "Body", true, 50, 50, 50, 10);
    objectsForE.push_back(equipE);
    Room roomE = Room("Room E", false, true, 4, objectsForE);

    vector<Object *> objectsForF;
    string eventAskScriptF = "\nDo you want to help clean the room? Maybe you'll find something!\nY. Yes\nN. No\n";
    Key *keyF = new Key("Key for Chest", "For Chest", false, 0);
    Event *eventF = new Event("Clean up this room", eventAskScriptF, "Wow! You find a key!", "Y", false, 0, 0, 0);
    objectsForF.push_back(eventF);
    objectsForF.push_back(keyF);
    Room roomF = Room("Room F", false, false, 5, objectsForF);

    vector<Object *> objectsForG;
    Equipment *equipG = new Equipment("Helmet", "Head", true, 80, 70, 60, 0);
    objectsForG.push_back(equipG);
    Room roomG = Room("Room G", false, false, 6, objectsForG);

    vector<Object *> objectsForH;
    Equipment *equipH = new Equipment("Helmet made in diamond", "Head", true, 150, 150, 150, 0);
    Key *keyH = new Key("Random key", "nothing", true, 0);
    objectsForH.push_back(keyH);
    objectsForH.push_back(equipH);
    Room roomH = Room("Room H", false, false, 7, objectsForH);

    vector<Object *> objectsForI;
    Potion *potionI = new Potion("Dragon killer", false, false, 0, 50, 0, 0);
    Event *eventI = new Event("You found a chest!", "\nDo you have the key for the chest?\n", "The chest is opened. There is a potion in the chest!", "For Chest", true, 0, 0, 0);
    objectsForI.push_back(eventI);
    objectsForI.push_back(potionI);
    Room roomI = Room("Room I", false, false, 8, objectsForI);

    vector<Object *> objectsForJ;
    vector<Item *> npcJCommodity;
    Equipment *equipJ = new Equipment("Ultimate Wand", "Right Hand", true, 50, 300, 100, 60);
    npcJCommodity.push_back(equipJ);
    NPC *npcJ = new NPC("Dumbledore", "I have a wand that can beat all the monster in the world.", npcJCommodity);
    objectsForJ.push_back(npcJ);
    Room roomJ = Room("Room J", false, false, 9, objectsForJ);

    vector<Object *> objectsForK;
    string monsterScriptK = "Congradulations! You beat Boss dragon. Thank you for saving people in this dungeon.";
    Monster *monsterK = new Monster("Boss dragon", monsterScriptK, 500, 80, 30, true);
    objectsForK.push_back(monsterK);
    Room roomK = Room("Room K", true, false, 10, objectsForK);

    this->rooms.push_back(roomA);
    this->rooms.push_back(roomB);
    this->rooms.push_back(roomC);
    this->rooms.push_back(roomD);
    this->rooms.push_back(roomE);
    this->rooms.push_back(roomF);
    this->rooms.push_back(roomG);
    this->rooms.push_back(roomH);
    this->rooms.push_back(roomI);
    this->rooms.push_back(roomJ);
    this->rooms.push_back(roomK);

    // build map
    this->rooms[0].setRightRoom(&this->rooms[3]);
    this->rooms[3].setLeftRoom(&this->rooms[0]);

    this->rooms[0].setDownRoom(&this->rooms[1]);
    this->rooms[1].setUpRoom(&this->rooms[0]);

    this->rooms[1].setRightRoom(&this->rooms[2]);
    this->rooms[2].setLeftRoom(&this->rooms[1]);

    this->rooms[2].setUpRoom(&this->rooms[3]);
    this->rooms[3].setDownRoom(&this->rooms[2]);

    this->rooms[3].setUpRoom(&this->rooms[4]);
    this->rooms[4].setDownRoom(&this->rooms[3]);

    this->rooms[4].setRightRoom(&this->rooms[5]);
    this->rooms[5].setLeftRoom(&this->rooms[4]);

    this->rooms[5].setUpRoom(&this->rooms[6]);
    this->rooms[6].setDownRoom(&this->rooms[5]);

    this->rooms[5].setRightRoom(&this->rooms[7]);
    this->rooms[7].setLeftRoom(&this->rooms[5]);

    this->rooms[7].setDownRoom(&this->rooms[8]);
    this->rooms[8].setUpRoom(&this->rooms[7]);

    this->rooms[8].setRightRoom(&this->rooms[9]);
    this->rooms[9].setLeftRoom(&this->rooms[8]);

    this->rooms[9].setDownRoom(&this->rooms[10]);
    this->rooms[10].setUpRoom(&this->rooms[9]);
}

/* Deal with player's moveing action */
void Dungeon::handleMovement()
{
    string goDirection;
    bool selectValid = false;
    while (!selectValid)
    {
        // list choice
        cout << endl
             << "Which way do you want to go?" << endl;
        bool haveU = false;
        bool haveD = false;
        bool haveR = false;
        bool haveL = false;
        if (this->player.getCurrentRoom()->getUpRoom() != nullptr)
        {
            haveU = true;
            cout << "U. Go up to " << this->player.getCurrentRoom()->getUpRoom()->getName();
            if (this->player.getCurrentRoom()->getUpRoom()->getIsLocked())
            {
                cout << "(Locked)";
            }
            cout << endl;
        }
        if (this->player.getCurrentRoom()->getDownRoom() != nullptr)
        {
            haveD = true;
            cout << "D. Go down to " << this->player.getCurrentRoom()->getDownRoom()->getName();
            if (this->player.getCurrentRoom()->getDownRoom()->getIsLocked())
            {
                cout << "(Locked)";
            }
            cout << endl;
        }
        if (this->player.getCurrentRoom()->getLeftRoom() != nullptr)
        {
            haveL = true;
            cout << "L. Go left to " << this->player.getCurrentRoom()->getLeftRoom()->getName();
            if (this->player.getCurrentRoom()->getLeftRoom()->getIsLocked())
            {
                cout << "(Locked)";
            }
            cout << endl;
        }
        if (this->player.getCurrentRoom()->getRightRoom() != nullptr)
        {
            haveR = true;
            cout << "R. Go right to " << this->player.getCurrentRoom()->getRightRoom()->getName();
            if (this->player.getCurrentRoom()->getRightRoom()->getIsLocked())
            {
                cout << "(Locked)";
            }
            cout << endl;
        }
        // player make choice
        cout << "> ";
        cin >> goDirection;
        if (haveU && (goDirection == "U" || goDirection == "u"))
        {
            selectValid = true;
            if (this->player.changeRoom(this->player.getCurrentRoom()->getUpRoom()))
            {
                cout << endl
                     << "Moving to " << this->player.getCurrentRoom()->getName() << endl;
            }
            else
            {
                cout << endl
                     << this->player.getCurrentRoom()->getUpRoom()->getName() << " is locked. You need a key to unlock." << endl;
            }
        }
        else if (haveD && (goDirection == "D" || goDirection == "d"))
        {
            selectValid = true;
            if (this->player.changeRoom(this->player.getCurrentRoom()->getDownRoom()))
            {
                cout << endl
                     << "Moving to " << this->player.getCurrentRoom()->getName() << endl;
            }
            else
            {
                cout << endl
                     << this->player.getCurrentRoom()->getDownRoom()->getName() << " is locked. You need a key to unlock." << endl;
            }
        }
        else if (haveL && (goDirection == "L" || goDirection == "l"))
        {
            selectValid = true;
            if (this->player.changeRoom(this->player.getCurrentRoom()->getLeftRoom()))
            {
                cout << endl
                     << "Moving to " << this->player.getCurrentRoom()->getName() << endl;
            }
            else
            {
                cout << endl
                     << this->player.getCurrentRoom()->getLeftRoom()->getName() << " is locked. You need a key to unlock." << endl;
            }
        }
        else if (haveR && (goDirection == "R" || goDirection == "r"))
        {
            selectValid = true;
            if (this->player.changeRoom(this->player.getCurrentRoom()->getRightRoom()))
            {
                cout << endl
                     << "Moving to " << this->player.getCurrentRoom()->getName() << endl;
            }
            else
            {
                cout << endl
                     << this->player.getCurrentRoom()->getRightRoom()->getName() << " is locked. You need a key to unlock." << endl;
            }
        }
        else
        {
            cout << "Invalid choice! Please choose again." << endl
                 << endl;
        }
    }
}

/* Deal with player's iteraction with objects in that room */
void Dungeon::handleEvent(Object *obj, int index)
{

    if (!obj->triggerEvent(&this->player))
    {
        return;
    }
    this->player.getCurrentRoom()->popObject(index);
    if (obj->getTag() == "Monster")
    {
        Monster *monster = dynamic_cast<Monster *>(obj);
        this->isBossAlive = !monster->getIsBoss();
    }
}

/* Deal with all game initial setting       */
/* Including create player, create map etc  */
void Dungeon::startGame()
{
    this->createMap();
    this->createPlayer();
}

/* Deal with the player's action     */
/* including showing the action list */
/* that player can do at that room   */
/* and dealing with player's input   */
void Dungeon::chooseAction(vector<Object *> roomObj)
{
    bool selectValid = false;
    while (!selectValid)
    {
        // list action
        cout << endl
             << "You are now in " << this->player.getCurrentRoom()->getName() << endl;
        cout << "What do you want to do?" << endl;
        cout << "0. Quit" << endl;
        int optionIndex = 1;
        for (int i = 0; i < roomObj.size(); i++)
        {
            string tag = roomObj[i]->getTag();
            if (tag == "Equipment")
            {
                Equipment *equip = dynamic_cast<Equipment *>(roomObj[i]);
                if (equip->getVisible())
                {
                    cout << optionIndex << ". ";
                    cout << "Pick up equipment ";
                    equip->printDetail();
                    cout << endl;
                    optionIndex++;
                }
            }
            else if (tag == "Potion")
            {
                Potion *potion = dynamic_cast<Potion *>(roomObj[i]);
                if (potion->getVisible())
                {
                    cout << optionIndex << ". ";
                    cout << "Pick up potion ";
                    potion->printDetail();
                    cout << endl;
                    optionIndex++;
                }
            }
            else if (tag == "Key")
            {
                Key *key = dynamic_cast<Key *>(roomObj[i]);
                if (key->getVisible())
                {
                    cout << optionIndex << ". ";
                    cout << "Pick up key ";
                    key->printDetail();
                    cout << endl;
                    optionIndex++;
                }
            }
            else if (tag == "Event")
            {
                Event *event = dynamic_cast<Event *>(roomObj[i]);
                cout << optionIndex << ". ";
                cout << "Event - " << event->getName();
                cout << endl;
                optionIndex++;
            }
            else if (tag == "NPC")
            {
                NPC *npc = dynamic_cast<NPC *>(roomObj[i]);
                cout << optionIndex << ". ";
                cout << "Talk to " << npc->getName();
                cout << endl;
                optionIndex++;
            }
            else if (tag == "Monster")
            {
                Monster *monster = dynamic_cast<Monster *>(roomObj[i]);
                cout << optionIndex << ". ";
                cout << "Battle with " << monster->getName() << " (Health: " << monster->getCurrentHealth() << ", Attack: " << monster->getAttack() << ", Defense: " << monster->getDefense() << ")";
                cout << endl;
                optionIndex++;
            }
        }
        cout << optionIndex << ". Move to other rooms" << endl;
        optionIndex++;
        cout << optionIndex << ". Show your status" << endl;
        optionIndex++;
        cout << optionIndex << ". Use equipment / potion in the backpack" << endl;
        optionIndex++;
        cout << optionIndex << ". Remove equipment and put it into backpack" << endl;

        int playerOption;
        cout << "> ";
        cin >> playerOption;

        // test quit
        if (playerOption == 0)
        {
            selectValid = true;
        }
        else

            if (playerOption > 0 && playerOption <= optionIndex)
        {
            selectValid = true;
        }
        else
        {
            cout << "Invalid choice! Choose again." << endl;
            continue;
        }

        // test quit
        if (playerOption == 0)
        {
            this->player.setCurrentHealth(0);
        }
        else

            if (playerOption == optionIndex)
        {
            // remove equipment
            player.removeEquipment();
        }
        else if (playerOption == optionIndex - 1)
        {
            // Use equipment / potion in the backpack
            this->player.listBackpackItemAndUse();
        }
        else if (playerOption == optionIndex - 2)
        {
            // show player status
            this->player.triggerEvent(&this->player);
        }
        else if (playerOption == optionIndex - 3)
        {
            // player move
            handleMovement();
        }
        else
        {
            // event
            handleEvent(roomObj[playerOption - 1], playerOption - 1);
        }
    }
}

/* Check whether the game should end or not */
/* Including player victory, or he/she dead */
bool Dungeon::checkGameLogic()
{
    // return this->player.getCurrentHealth() <= 0 || this->player.getCurrentRoom()->getIsExit();
    return this->player.getCurrentHealth() <= 0 || (this->player.getCurrentRoom()->getIsExit() && !this->isBossAlive);
}

/* Deal with the whole game process */
void Dungeon::runDungeon()
{
    startGame();
    bool isGameEnd = false;
    while (!isGameEnd)
    {
        chooseAction(this->player.getCurrentRoom()->getObjects());
        isGameEnd = checkGameLogic();
    }
    cout << "Game end." << endl;
}

void Dungeon::setIsBossAlive(bool isBossAlive)
{
    this->isBossAlive = isBossAlive;
}

bool Dungeon::getIsBossAlive()
{
    return this->isBossAlive;
}
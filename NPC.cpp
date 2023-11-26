#include "NPC.h"

NPC::NPC() : GameCharacter()
{
}

NPC::NPC(string name, string script, vector<Item *> commodity) : GameCharacter(name, "NPC")
{
    this->script = script;
    this->commodity = commodity;
}

// Done
void NPC::listCommodity()
{
    cout << "Commodities: " << endl;
    int index = 1;
    for (Item *i : this->commodity)
    {
        cout << "- " << index << ". ";
        i->printDetail();
        cout << endl;
        index++;
    }
    cout << endl;
}

// Done
/* Virtual function that you need to complete   */
/* In NPC, this function should deal with the   */
/* transaction in easy implementation           */
bool NPC::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player *>(obj);
    // show script
    cout << endl << this->getName() << ": " << this->getScript() << endl;

    // ask player
    cout << endl
         << "Do you want to see all " << this->getName() << "'s commodities? (Y/N)" << endl;
    string seeCommodity;
    cin >> seeCommodity;
    if (seeCommodity != "Y" && seeCommodity != "y")
    {
        return false;
    }

    // show commodity
    cout << endl;
    if (this->commodity.size() == 0)
    {
        cout << this->getName() << ": There is nothing I can give you." << endl;
        return false;
    }

    this->listCommodity();
    int lastSelectionIndex = this->commodity.size() + 1;

    // ask player's selection and pickup commodity
    bool selectValid = false;
    string playerSelectStr;
    while (!selectValid)
    {
        cout << "Which commodity do you want? (or " << this->commodity.size() + 1 << ". None)" << endl;
        cin >> playerSelectStr;
        bool isplayerSelectNum = all_of(playerSelectStr.begin(), playerSelectStr.end(), ::isdigit);
        if (isplayerSelectNum && stoi(playerSelectStr) > this->commodity.size() + 1)
        {
            cout << "Wrong answer! Choose again." << endl
                 << endl;
        }
        else
        {
            selectValid = true;
        }
    }

    // player select
    int playerSelect = stoi(playerSelectStr);
    int playerSelObjIndex = playerSelect - 1;
    selectValid = true;
    if (player->getMoney() < this->commodity[playerSelObjIndex]->getPrice())
    {
        cout << "You don't have enough money to trade!" << endl;
        return false;
    }

    player->setMoney(player->getMoney() - this->commodity[playerSelObjIndex]->getPrice());
    this->commodity[playerSelObjIndex]->triggerEvent(player);
    this->commodity.erase(this->commodity.begin() + playerSelect - 1);

    return false;
}

/* Set & Get function*/
void NPC::setScript(string script)
{
    this->script = script;
}
void NPC::setCommodity(vector<Item *> commodity)
{
    this->commodity = commodity;
}
string NPC::getScript()
{
    return this->script;
}
vector<Item *> NPC::getCommodity()
{
    return this->commodity;
}
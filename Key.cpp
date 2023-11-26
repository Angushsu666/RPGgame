#include "Key.h"

Key::Key() : Item()
{
}

Key::Key(string name, string content, bool visible, int price) : Item(name, "Key", visible, 0, 0, 0, price)
{
    this->content = content;
}

string Key::getContent()
{
    return this->content;
}
void Key::setContent(string content)
{
    this->content = content;
}
bool Key::triggerEvent(Object *obj)
{
    Player *player = dynamic_cast<Player *>(obj);
    cout << endl << "Get key: " << this->getName() << endl;
    player->addItem(this, true);
    return true;
}